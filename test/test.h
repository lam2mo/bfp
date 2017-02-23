#ifndef __TEST_H
#define __TEST_H

#define TEST_OP2(OP, NBITS, ES)                                                \
    Posit a = Posit(NBITS, ES);                                                \
    Posit b = Posit(NBITS, ES);                                                \
                                                                               \
    for (int i = 0; i < (1 << NBITS); i++) {                                   \
        a.setBits(i);                                                          \
        for (int j = 0; j < (1 << NBITS); j++) {                               \
            b.setBits(j);                                                      \
                                                                               \
            Posit c = a.OP(b);                                                 \
                                                                               \
            if (OP ## _table[j][i] == -1) {                                    \
                CuAssertTrue(tc, c.isNan());                                   \
            } else {                                                           \
                CuAssertTrue(tc, !c.isNan());                                  \
                CuAssertTrue(tc, c.getBits() ==                                \
                                 (POSIT_UTYPE)OP ## _table[j][i]);             \
            }                                                                  \
        }                                                                      \
    }

#endif
