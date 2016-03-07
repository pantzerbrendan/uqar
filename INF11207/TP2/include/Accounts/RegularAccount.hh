#ifndef REGULARACCOUNT_HH_
#define REGULARACCOUNT_HH_

#include "Accounts/A_Account.hh"

class RegularAccount : public A_Account {
private:
    /* data */
public:
    RegularAccount (User *owner, u_int id);
    virtual ~RegularAccount ();
};

#endif /* !REGULARACCOUNT_HH_ */
