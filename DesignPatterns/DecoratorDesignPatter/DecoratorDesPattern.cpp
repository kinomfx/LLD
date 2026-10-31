#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ; 

class ICharacter{
    public : 
    virtual string getAbilities() = 0 ; 
};

class Mario : public ICharacter{
    string getAbilities(){
        return "Mario";
    }
};

class Decorator : public ICharacter { 
    public: 
    virtual string getAbilities() = 0 ; 
    ICharacter* character ; 

};

class HeightUpDec : public Decorator{
    public :    
    HeightUpDec(ICharacter* character){
        this->character = character ; 
    }
    string getAbilities(){
        return this->character->getAbilities() + " " + "Heighten Up-ed";
    }
};

class GunPowerDec : public Decorator{
    public :    
    GunPowerDec(ICharacter* character){
        this->character = character ; 
    }
    string getAbilities(){
        return this->character->getAbilities() + " " + "Gun Power-ed";
    }
};

class StarPowerDec : public Decorator{
    public :    
    StarPowerDec(ICharacter* character){
        this->character = character ; 
    }
    string getAbilities(){
        return this->character->getAbilities() + " " + "Star Power-ed";
    }
};
int main(){
    ICharacter* mario = new HeightUpDec(new GunPowerDec(new StarPowerDec(new Mario())));
    cout<<mario->getAbilities();
    return 0 ; 
}