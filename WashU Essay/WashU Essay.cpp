#include <iostream>
using namespace std;

void acceptAugustRothpletz();
bool accepted = false;

int main()
{
    cout<<"Why I code in red and green:"<<endl;

    cout<<"Ever since stumbling upon a Khan Academy JavaScript course out of pandemic boredom, software development has become the hobby I dream of transforming into a career."<<endl;

    cout<<"--Washington University’s computer science program has an extensive variety of course offerings, such as AI and Society (CSE 411A) and Video Game Programming (CSE 450A), would allow me to individualize my major, ensuring my studies best align with my interests and skill sets."<<endl;

    cout<<"--Close proximity to the world-class Olin Business School would allow me to diversify my skillset with an entrepreneurship minor." << endl;

    cout<<"--Wash U’s unofficial motto, 'Know people by their name and their story' was exemplified through the faculty I met (Dr. Siever and Dr. Bogost). Their passion and responsiveness to a prospective student speaks volumes." << endl;

    cout<<"--The students I met had an intellectual curiosity beyond their major and a drive to be a catalyst of global change, just like me." << endl;



    while(!accepted){
        cout<<"Did You like my essay?";
        string choice;
        cin>>choice;
        if(choice=="Yes"){
            acceptAugustRothpletz();
        }
        else {
            cout<<"Please, reconsider!"<<endl;
        }
    }
    return 0;
}


void acceptAugustRothpletz() {
    accepted = true;
    cout << "Thanks for your consideration!";
}

//Test my code!--> https://replit.com/@AugustRothpletz/WashU-Essay?v=1
