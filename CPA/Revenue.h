class Revenue
{
	float demand;
	float price;
  public:
  	Revenue(float myDemand, float myPrice);
  	float getRevenueValue();
  	float getDemand();
  	float getPrice();
};

Revenue::Revenue(float myDemand, float myPrice)
{
	demand = myDemand;
	price = myPrice;
}

float Revenue::getRevenueValue()
{
	return price * demand;
}

float Revenue::getDemand()
{
	return demand;
}

float Revenue::getPrice()
{
	return price;
}