#include <stdio.h>
#include <stdlib.h>

#define MAX_DICT_SIZE 4096
#define MAX_CODE_LENGTH 12
#define MAX_TREE_HT 100

// BYTERUN 
void byteRunEncode(FILE *input, FILE *output) {
    int currChar, nextChar, count;

    while ((currChar = fgetc(input)) != EOF) {
        fputc(currChar, output);
        count = 1;

        while ((nextChar = fgetc(input)) == currChar && count < 255) {
            count++;
        }

        fprintf(output, "%d", count);

        if (nextChar != EOF) {
            ungetc(nextChar, input);
        }
    }
}

// HUFFMAN 
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top, FILE* outputFile) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, outputFile);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, outputFile);
    }

    if (isLeaf(root)) {
        fprintf(outputFile, "%c: ", root->data);
        for (int i = 0; i < top; ++i)
            fprintf(outputFile, "%d", arr[i]);
        fprintf(outputFile, "\n");
    }
}

void HuffmanCodesFromFile(FILE* inputFile, FILE* outputFile) {
    int freq[256] = {0};  
    char ch;
    while (fscanf(inputFile, "%c", &ch) != EOF) {
        freq[(int)ch]++;
    }

    char data[256];
    int freq_new[256];
    int size = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            data[size] = (char)i;
            freq_new[size] = freq[i];
            size++;
        }
    }

    struct MinHeapNode* root = buildHuffmanTree(data, freq_new, size);

    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top, outputFile);
}

// LZW
typedef struct {
    int code;
    char value;
} dictionary;

dictionary dict[MAX_DICT_SIZE];

void initializeDictionary() {
    for(int i = 0; i < MAX_DICT_SIZE; i++) {
        dict[i].code = i;
        dict[i].value = (char)i;
    }
}

int searchDictionary(char currentChar, int previousCode) {
    for(int i = 256; i < MAX_DICT_SIZE; i++) {
        if(dict[i].value == currentChar && dict[i].code == previousCode)
            return i;
    }
    return -1;
}

void compressLZW(FILE *input, FILE *output) {
    initializeDictionary();
    int nextCode = 256;
    int currentChar = fgetc(input);
    int previousCode = currentChar;

    while((currentChar = fgetc(input)) != EOF) {
        int searchResult = searchDictionary(currentChar, previousCode);
        if(searchResult != -1) {
            previousCode = searchResult;
        } else {
            fwrite(&previousCode, sizeof(int), 1, output);
            if(nextCode < MAX_DICT_SIZE) {
                dict[nextCode].code = previousCode;
                dict[nextCode].value = currentChar;
                nextCode++;
            }
            previousCode = currentChar;
        }
    }
    fwrite(&previousCode, sizeof(int), 1, output);
}


int main() {
    int choice;
    printf("Choose encoding method:\n1. ByteRun\n2. LZW\n3. Huffman\n");
    scanf("%d", &choice);

    FILE *inputFile = fopen("input5.txt", "r");
    FILE *outputFile = fopen("output5.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    switch(choice) {
        case 1:
            byteRunEncode(inputFile, outputFile);
            break;
        case 2:
            compressLZW(inputFile, outputFile);
            break;
        case 3:
            HuffmanCodesFromFile(inputFile, outputFile);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}