
#pragma once

#include <string>
#include <cstddef>

enum e_acronyms {
    INF10107, INF11107, INF1407,
    INF16107, MAT13203, INF11207,
    INF15107, INF23107, INF26207,
    MAT14107, GEN12303, MUS12097,
    NB_ACRONYMS
};

typedef struct  s_acronyms
{
    std::string names[NB_ACRONYMS];
    bool        selected[NB_ACRONYMS];

    bool        (*activate)(struct s_acronyms *, const e_acronyms);
    bool        (*deactivate)(struct s_acronyms *, const e_acronyms);
    void        (*ToString)(struct s_acronyms *);
    void        (*CSVFormatter)(struct s_acronyms *);
    size_t      (*CountSelected)(struct s_acronyms *);
}               Acronyms;

void    AcronymsInit(Acronyms *);
void    AcronymsDestroy(Acronyms *);
