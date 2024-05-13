#include<bits/stdc++.h>
// Header Files End

using namespace std;


class Pizza{

public:
    map<string,int> pizza_base_price;
    map<string,int> pizza_toppings_price;

    Pizza(){

        pizza_toppings_price["Mozzarella cheese"]=30;
        pizza_toppings_price["Cheddar cheese"]=35;
        pizza_toppings_price["Spinach"]=20;
        pizza_toppings_price["Corn"]=15;
        pizza_toppings_price["Mushroom"]=15;
        pizza_toppings_price["Pepperoni"]=45;

        pizza_base_price["Regular"]=50;
        pizza_base_price["Whole Wheat"]=75;

    }

};

class AddOn{

public:

    map<string,int> drink_price;
    map<string,int> dessert_price;

    AddOn(){

        drink_price["Pepsi"]=17;
        drink_price["7-up"]=19;
        drink_price["Coke"]=20;
        dessert_price["Lava cake"]=95;
        dessert_price["Chocolate brownie"]=86;
    }

};

class Order{

public:

    vector<string> toppings;
    string base;
    string sauce;
    vector<string> drinks,desserts;
    float discount_percentage=5;

    Pizza pizza_stats;
    AddOn addOn_stats;

    Order(vector<string> &toppings,string &base,string &sauce,vector<string> &drinks,vector<string> &desserts){
        this->toppings=toppings;
        this->base=base;
        this->sauce=sauce;
        this->drinks=drinks;
        this->desserts=desserts;
    }

    float calculateDiscount(float total_price_before_discount){
        if(drinks.size()==0||desserts.size()==0)return 0.0;

        return (total_price_before_discount*discount_percentage)/100.0;
    }

    void generateBill(){

        float total_bill=0.0;

        string calculation="";

        total_bill+=pizza_stats.pizza_base_price[base];
        calculation+=to_string(pizza_stats.pizza_base_price[base])+" (Base) + (";

        for(int i=0;i<toppings.size();i++){
            total_bill+=pizza_stats.pizza_toppings_price[toppings[i]];
            calculation+=to_string(pizza_stats.pizza_toppings_price[toppings[i]]);
            if(i==toppings.size()-1)calculation+=") (Toppings) ";
            else calculation+="+ ";
        }
        

        for(int i=0;i<drinks.size();i++){
            total_bill+=addOn_stats.drink_price[drinks[i]];
            calculation+=to_string(addOn_stats.drink_price[drinks[i]]);
            if(i!=drinks.size()-1)calculation+=" + ";
        }

        for(int i=0;i<desserts.size();i++){
            if(i==0)calculation+=" + ";
            total_bill+=addOn_stats.dessert_price[desserts[i]];
            calculation+=to_string(addOn_stats.dessert_price[desserts[i]]);
            if(i!=desserts.size()-1)calculation+=" + ";
        }
        calculation+=" ";

        float total_discount=calculateDiscount(total_bill);

        total_bill-=total_discount;
        calculation+="- "+to_string(total_discount)+" (Discount) = ";

        calculation+=to_string(total_bill);

        cout<<"Amount to be paid: "<<total_bill<<" "<<calculation<<endl;

    }

};


int main(){

    vector<string> toppings;
    toppings.push_back("Mozzarella cheese");
    toppings.push_back("Pepperoni");
    string base="Whole Wheat";
    vector<string> drinks(1,{"Coke"});
    vector<string> desserts(1,{"Lava cake"});
    string sauce="Regular";

    Order currOrder(toppings,base,sauce,drinks,desserts);

    currOrder.generateBill();
    
}

