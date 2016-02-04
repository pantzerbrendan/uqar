
#include <ostream>
#include "data/Acronyms.hh"

/* STATIC FUNCTION PROTOTYPES */
static bool     activate(Acronyms *, const e_acronyms);
static bool     deactivate(Acronyms *, const e_acronyms);
static std::string     AC_ToString(Acronyms *);
static std::string     AC_CSVFormatter(Acronyms *);
static size_t   CountSelected(Acronyms *);
/* !STATIC FUNCTION PROTOTYPES */

void    AcronymsInit(Acronyms *acronyms)
{
    acronyms->names[INF10107] = "INF10107";
    acronyms->names[INF11107] = "INF11107";
    acronyms->names[INF1407] = "INF1407";
    acronyms->names[INF16107] = "INF16107";
    acronyms->names[MAT13203] = "MAT13203";
    acronyms->names[INF11207] = "INF11207";
    acronyms->names[INF15107] = "INF15107";
    acronyms->names[INF23107] = "INF23107";
    acronyms->names[INF26207] = "INF26207";
    acronyms->names[MAT14107] = "MAT14107";
    acronyms->names[GEN12303] = "GEN12303";
    acronyms->names[MUS12097] = "MUS12097";

    for (size_t i = 0; i <= NB_ACRONYMS; i++)
        acronyms->selected[i] = false;

    acronyms->activate = &activate;
    acronyms->deactivate = &deactivate;
    acronyms->ToString = &AC_ToString;
    acronyms->CSVFormatter = &AC_CSVFormatter;
    acronyms->CountSelected = &CountSelected;
}

void    AcronymsDestroy(Acronyms *acronyms)
{
    if (acronyms)
        delete acronyms;
}

/* Static Functions */

/*
**
*/
static bool     activate(Acronyms *acr, const e_acronyms id)
{
    if (acr->CountSelected(acr) >= 5) return (false);
    acr->selected[id] = true;
    return (true);
}

/*
**
*/
static bool     deactivate(Acronyms *acr, const e_acronyms id)
{
    acr->selected[id] = false;
    return (true);
}

/*
**
*/
static std::string     AC_ToString(Acronyms *acr)
{
    std::string result = "";
    for (int i = 0; i < NB_ACRONYMS; i++)
    {
        if (acr->selected[i]) result += acr->names[i] + ", ";
    }
    result = result.substr(0, result.size() - 2); // removes the last ", "
    return (result);
}

/*
**
*/
static std::string     AC_CSVFormatter(Acronyms *acr)
{
    std::string result = "";
    for (int i = 0; i < NB_ACRONYMS; i++)
    {
        if (acr->selected[i]) result += acr->names[i] + ";";
    }
    result = result.substr(0, result.size() - 1); // removes the last semi-column
    return (result);
}

/*
**
*/
static size_t   CountSelected(Acronyms *acr)
{
    size_t count = 0;
    for (int i = 0; i < NB_ACRONYMS; i++)
    if (acr->selected[i]) count++;
    return (count);
}

std::ostream    &operator<<(std::ostream &stream, const Acronyms &acr)
{
    int added = 0;
    for (int i = 0; i < NB_ACRONYMS; i++)
    {
        if (added != 0) stream << ", ";
        if (acr.selected[i])
        {
            stream << acr.names[i];
            added++;
        }
    }
    return (stream);
}
