#include "Headerr.h"
#include "Functii.cpp"


int main()
{
    srand(time(NULL));
    introduction();
    cout<< "                        Press ENTER to continue!"<<endl;
    cin.get();
    system("cls");
    char optiune;
    do {
            Menu();
            cin>>optiune;
            while(optiune != '1' && optiune !='2' && optiune != '3' && optiune != '4' && optiune != '5')
            {
                cout<<"\n\n\t Enter a value between 1 and 5 : ";
                cin>>optiune ;
            }
            if(optiune == '1')
                Rules();
            if(optiune == '2')
                Player_vs_Computer();
            if(optiune == '3')
                Player_vs_Player();
            if(optiune == '4')
                show_history_pvc();
            system("cls");
    }while(optiune != '5');

    return 0;
}

