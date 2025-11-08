
#ifndef PSL1GHT__OPD_ENTRY_H
#define PSL1GHT__OPD_ENTRY_H

__attribute__((packed, aligned(3)))
struct psl1ght__opd_entry_s
{

    union {

        struct {

            unsigned int procedure_entry;

            unsigned int tocbase32;

        } celloslv2;

        unsigned long long procedure_entry;

    };

    unsigned long long tocbase;

    unsigned long long environment;

};

#endif/*PSL1GHT__OPD_ENTRY_H*/
