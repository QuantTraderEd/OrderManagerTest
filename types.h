#ifndef TYPES_H
#define TYPES_H

// A server can insert orders, from the client's perspective
class IOrderServer
{
public:
  virtual ~IOrderServer() = default;
  virtual void InsertOrder(int volume, double price, int tag, bool side) = 0;
};

// Common arguments when inserting orders
struct InsertArgs
{
  const int& mVolume;
  const double& mPrice;
  const bool& mSide;
};

// A component to check orders before sending them to the market
class IOrderExecutor
{
public:
  virtual ~IOrderExecutor() = default;
  virtual bool AttemptInsertOrder(const InsertArgs&, int tag) = 0;
};

// A component to handle responses from market modules
class IMarketModuleResponseHandler
{
public:
  virtual ~IMarketModuleResponseHandler() = default;
  virtual void OnOrderError(int tag) = 0;
};

// A market module sends orders to the market
class IMarketModule
{
public:
  virtual ~IMarketModule() = default;
  virtual IOrderServer& GetOrderServer() = 0;
  virtual void Initialise(IMarketModuleResponseHandler*, IOrderExecutor*) = 0;
  virtual void InsertOrder(int volume, double price, int tag, bool side) = 0;
};

// Implementation of the "key passing idiom", with friend access to templated types
class AccessKey   {
private:
  AccessKey() = default;
  AccessKey(const AccessKey&) = default;
  template<typename MarketModule> friend void SetupOrderHandlers(MarketModule*); // let handler setup function have access
  template<typename InsertHandler> friend class OrderServer; // let server have access
};

#endif // TYPES_H
