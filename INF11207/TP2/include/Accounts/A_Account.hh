#ifndef AACCOUNT_HH_
#define AACCOUNT_HH_

#include "factory/FactoryBaseType.hpp"
#include "users/User.hpp"

typedef unsigned int u_int;

class A_Account : public Factories::FactoryBaseType {
private:
  u_int     _id;
  User      *_owner;
  double    _balance;

public:
  A_Account (User *owner, u_int id);
  virtual ~A_Account ();

  double            getBalance() const;
  virtual double    withdrawal(const double amount);
  virtual void      deposit(const double amount);
};

#endif /* !AACCOUNT_HH_ */
