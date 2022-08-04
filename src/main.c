
#include <zlib.h>
#include <stdio.h>
#include <string.h>

#include "kseq.h"

KSEQ_INIT(gzFile, gzread)

int main(int argc, char** fname) {
    gzFile fp;
    kseq_t *seq;

    fp = gzopen(fname[1], "r");
    seq = kseq_init(fp);
    size_t n = 0;
    while (kseq_read(seq) >= 0) {
        ++n;
        fprintf(stdout, "Name: %s\n", seq->name.s);
        fprintf(stdout, "Length: %zu\n", seq->seq.l);
        fprintf(stdout, "Comment: %s\n", seq->comment.s);
        if (seq->qual.l >= 0) {
            fprintf(stdout, "Qual: %s\n", seq->qual.s);
        } else {
            fprintf(stdout, "Qual: Missing\n");
        }
        fprintf(stdout, "\n");
    }
    kseq_destroy(seq);
    gzclose(fp);
    return 0;
}