#include "Huffman.h"

int main()
{
    std::vector<int> v{1,3,5,7};
    HuffmanTree<int> hf;
    hf.CreateHuffmanTree(v);
    return 0;
}
