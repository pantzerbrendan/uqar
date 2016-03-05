#ifndef AACCOUNT_HH_
#define AACCOUNT_HH_

#include "factory/FactoryBaseType.hh"

typedef unsigned double u_double;

class A_Account : public FactoryBaseType {
private:
  int       _id;
  User      *_owner;
  u_double  _balance;

public:
  A_Account (arguments);
  virtual ~A_Account ();

  u_double    getBalance() const;
  virtual double      withdrawal(const double amount);
  virtual void        deposit(const double amount);
};

#endif /* !AACCOUNT_HH_ */
