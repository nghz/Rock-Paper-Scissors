#include <iostream>

using namespace std;

class Tool
{
private:
    int Strength;
    char type;

public:
    Tool() {}

    Tool(int streng , char tpy)
    {
        setStrength(streng);
        setType(tpy);
    }
    void setStrength(int strg)
    {
        Strength = strg ;
    }
    void setType(char tp)
    {
        type = tp;
    }
    int getStrength()
    {
        return Strength;
    }
    char gettype()
    {
        return type;
    }
    virtual bool fight(Tool &) = 0;

};
class Rock :public Tool
{
public:
    Rock(int rc) //: Tool(rc , 'r')
    {
        setStrength(rc);
        setType('r');
    }
    virtual bool fight(Tool &tool)
    {
        if(tool.gettype() == 'p')
        {
              if(getStrength() > 2 * tool.getStrength())
              return true;
          else
              return false;

        }
        else
            if(tool.gettype() == 's')
       {
          if(getStrength() <=  0.5 * tool.getStrength())
              return false;
          else
              return true;
       }

    }

};
class Paper :public Tool
{
public:
    Paper(int prp) //: Tool(prp , 'p')
    {
        setStrength(prp);
        setType('p');
    }
    virtual bool fight(Tool &tool)
    {
        if(tool.gettype() == 's')
        {
              if(getStrength() > 2 * tool.getStrength())
              return true;
          else
              return false;
        }
        else
            if(tool.gettype() == 'r')
       {
          if(getStrength() <=  0.5 * tool.getStrength())
              return false;
          else
              return true;
       }
       if(tool.gettype() == 'p')
       {
           return getStrength();
       }

    }
};
class Scissors :public Tool
{
public:
    Scissors(int sci) //: Tool(sci , 's')
    {
        setStrength(sci);
        setType('s');
    }
    virtual bool fight(Tool &tool)
    {
       if(tool.gettype() == 'r')
        {
              if(getStrength() > 2 * tool.getStrength())
              return true;
          else
              return false;
        }
        else
            if(tool.gettype() == 'p')
       {
          if(getStrength() <=  0.5 * tool.getStrength())
              return false;
          else
              return true;
       }
       if(tool.gettype() == 's')
       {
           return getStrength();
       }
    }
};

int main()
{
int rock,paper,scissors;
cin >>rock>>paper>>scissors;

Rock rc(rock);
Paper prp(paper);
Scissors sci(scissors);
Tool *p[3];
p[0]=&rc;
p[1]=&prp;
p[2]=&sci;
cout<<"\\"<<"\tR" << "\tP" << "\tS" << endl;
cout<<"R";
cout<<"\tE";
if(rc.fight(prp))
{
    cout<<"\tW";
}
else
{
    if(rc.fight(prp)== prp.fight(rc))
    {
        cout<<"\tE";
    }
    else
    {
    cout<<"\tL";
    }
}
if(rc.fight(sci))
{
    cout<<"\tW";
}
else
{
    if(rc.fight(sci)== sci.fight(rc))
    {
        cout<<"\tE";
    }
    else
    {
        cout<<"\tL";
    }
}


cout<<endl<<"P";
if(prp.fight(rc))
{
    cout<<"\tW";
}
else
{
    if(prp.fight(rc)== rc.fight(prp))
    {
        cout<<"\tE";
    }
    else
    {
        cout<<"\tL";
    }

}
cout<<"\tE";
if(prp.fight(sci))
{
    cout<<"\tW";
}
else
{
    if(prp.fight(sci)== sci.fight(prp))
    {
        cout<<"\tE";
    }
    else
    {
        cout<<"\tL";
    }

}


cout<<endl<<"S";
if(sci.fight(rc))
{
    cout<<"\tW";
}
else
{
    if(sci.fight(rc)== rc.fight(sci))
    {
        cout<<"\tE";
    }
    else
    {
        cout<<"\tL";
    }
}
if(sci.fight(prp))
{
    cout<<"\tW";
}
else
{
    if(sci.fight(prp)== prp.fight(sci))
    {
        cout<<"\tE";
    }
    else
    {
        cout<<"\tL";
    }

}
cout<<"\tE";

    return 0;
}
