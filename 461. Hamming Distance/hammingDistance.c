int hammingDistance(int x, int y) {

    register int count = (((0x00000001&x)!=(0x00000001&y)) ? 1 : 0)
                       + (((0x00000002&x)!=(0x00000002&y)) ? 1 : 0)
                       + (((0x00000004&x)!=(0x00000004&y)) ? 1 : 0)
                       + (((0x00000008&x)!=(0x00000008&y)) ? 1 : 0)
                       + (((0x00000010&x)!=(0x00000010&y)) ? 1 : 0)
                       + (((0x00000020&x)!=(0x00000020&y)) ? 1 : 0)
                       + (((0x00000040&x)!=(0x00000040&y)) ? 1 : 0)
                       + (((0x00000080&x)!=(0x00000080&y)) ? 1 : 0)
                       + (((0x00000100&x)!=(0x00000100&y)) ? 1 : 0)
                       + (((0x00000200&x)!=(0x00000200&y)) ? 1 : 0)
                       + (((0x00000400&x)!=(0x00000400&y)) ? 1 : 0)
                       + (((0x00000800&x)!=(0x00000800&y)) ? 1 : 0)
                       + (((0x00001000&x)!=(0x00001000&y)) ? 1 : 0)
                       + (((0x00002000&x)!=(0x00002000&y)) ? 1 : 0)
                       + (((0x00004000&x)!=(0x00004000&y)) ? 1 : 0)
                       + (((0x00008000&x)!=(0x00008000&y)) ? 1 : 0)
                       + (((0x00010000&x)!=(0x00010000&y)) ? 1 : 0)
                       + (((0x00020000&x)!=(0x00020000&y)) ? 1 : 0)
                       + (((0x00040000&x)!=(0x00040000&y)) ? 1 : 0)
                       + (((0x00080000&x)!=(0x00080000&y)) ? 1 : 0)
                       + (((0x00100000&x)!=(0x00100000&y)) ? 1 : 0)
                       + (((0x00200000&x)!=(0x00200000&y)) ? 1 : 0)
                       + (((0x00400000&x)!=(0x00400000&y)) ? 1 : 0)
                       + (((0x00800000&x)!=(0x00800000&y)) ? 1 : 0)
                       + (((0x01000000&x)!=(0x01000000&y)) ? 1 : 0)
                       + (((0x02000000&x)!=(0x02000000&y)) ? 1 : 0)
                       + (((0x04000000&x)!=(0x04000000&y)) ? 1 : 0)
                       + (((0x08000000&x)!=(0x08000000&y)) ? 1 : 0)
                       + (((0x10000000&x)!=(0x10000000&y)) ? 1 : 0)
                       + (((0x20000000&x)!=(0x20000000&y)) ? 1 : 0)
                       + (((0x40000000&x)!=(0x40000000&y)) ? 1 : 0)
                       + (((0x80000000&x)!=(0x80000000&y)) ? 1 : 0);

    return count;
}