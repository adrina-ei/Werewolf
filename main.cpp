#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;
int main(void)
{

    cout << "                                                                                                                        " << endl;
    cout << "                                                                                                                        " << endl;
    cout << "   ____________________________________________________________________________________________________________________" << endl;
    cout << "  |____________________________________________________________________________________________________________________|" << endl;
    cout << "  ||                                                                                                                  ||" << endl;
    cout << "  ||                                                                                                                  ||" << endl;
    cout << "  ||                                                                                                                  ||" << endl;
    cout << "  ||    ***                                   ***           ****               ***                 ***************    ||" << endl;
    cout << "  ||     ***                                 ***         ***    ***            ***                 ***************    ||" << endl;
    cout << "  ||      ***                               ***        ***        ***          ***                 ***                ||" << endl;
    cout << "  ||       ***                             ***       ***            ***        ***                 ***                ||" << endl;
    cout << "  ||        ***                           ***      ***                ***      ***                 ***                ||" << endl;
    cout << "  ||         ***                         ***      ***                  ***     ***                 *********          ||" << endl;
    cout << "  ||          ***         *****         ***       ***                  ***     ***                 *********          ||" << endl;
    cout << "  ||           ***       *** ***       ***         ***                ***      ***                 ***                ||" << endl;
    cout << "  ||            ***     ***   ***     ***            ***            ***        ***                 ***                ||" << endl;
    cout << "  ||             ***   ***     ***   ***               ***        ***          ***                 ***                ||" << endl;
    cout << "  ||              *** ***       *** ***                  ***    ***            ***************     ***                ||" << endl;
    cout << "  ||               *****         *****                      ****               ***************     ***                ||" << endl;
    cout << "  ||                                                                                                                  ||" << endl;
    cout << "  ||                                                                                                                  ||" << endl;
    cout << "  ||__________________________________________________________________________________________________________________||" << endl;
    cout << "  |____________________________________________________________________________________________________________________|" << endl;
    cout << endl;
    cout << endl;
    cout << "                       ___________________<< WELCOME TO THE WEREWOLF GAME >> ___________________" << endl;
    cout << endl;
    cout << endl;
    cout << "  ______________________________________________________________________________________________________________________" << endl;
    cout << endl;
    cout << endl;

    int n;
    cout << "Enter the number of players:" << endl;
    cin >> n;
    cout << endl;
    cout << "  ______________________________________________________________________________________________________________________" << endl;
    char names[n][20]={},lover1[20]={},lover2[20]={},oil[20]={},protect[20]={},kill[20]={},hunt[20]={},hunt_or_rest[5]={},eat[20]={},cult[20]={};
    int game[n][6]={},role[8]={1,1,1,1,1,1,(n-6)/4,(n-6)-((n-6)/4)},numlove1,numlove2,numhunt=2,votes[n+1]={0},alive=n;
    int role1[8]={1,1,1,1,1,1,(n-6)/4,(n-6)-((n-6)/4)};
    char roles[8][20]={"Serial Killer","Fire","Guardian Angel","Goddess","Cult","Hunter","Wolf","Villager"};
    bool goddess = false;

    //names
    cout << endl;
    cout << "Enter the players' name: " << endl;
    for( int i=0 ; i<n ; i++)
        cin >> names[i];
    cout << "  ______________________________________________________________________________________________________________________" << endl;


    //roles(0)a
    cout << "\n" << "These are the Roles:" << "\a" << endl;

    for( int j=0 ; j<n ; j++)
    {
        int a = rand()%8;
        if(role[a]>0)
        {
            game[j][0]=a;
            role[a]--;

            cout << names[j]<< "\t" << roles[a]<<"\n";
        }
        else
            j--;
    }
    cout << "  ______________________________________________________________________________________________________________________" << endl;


    /*roles(0)a  vote(1)0  life(2)1  lover(3)0  oil(4)0  protect(5)0*/

    for( int k=0 ; k<n ; k++)
    {
        game[k][1]=0;
        game[k][2]=1;
        game[k][3]=0;
        game[k][4]=0;
        game[k][5]=0;
    }

    //play

    while(true)
    {
        cout << "\n" << "It's Night!"<< endl << endl;

        //Guardian Angel(5)
        if(role1[2]==1)
        {
            cout << "Guardian Angel! Who do u wanna \"Protect\"?" << endl;
            cin >> protect;
            for( int i=0 ; i<n ; i++)
            {
                if(!strcmp(protect,names[i]))
                {
                    if(game[i][2]==0)
                    {
                        cout << names[i] << " is already dead. I can't do anything for him/her." << endl;
                        break;
                    }
                    else
                    {
                    game[i][5]=1;
                    cout << names[i] << " is \"Protected\" tonight." << endl;
                    break;
                    }

                }
            }
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            cout << endl;
        }

        //Goddess(3)
        if(role1[3]==1)
        {
            if(goddess == false)
            {
                cout << "Goddess! Who are the Lovers?" << endl;

                cin >> lover1 >> lover2;

                for( int j=0 ; j<n ; j++)
                {
                    if( !strcmp(lover1,names[j]))
                    {
                        if(game[j][2]==0)
                        {
                            cout << names[j] << " is already dead. I can't do anything for him/her." << endl;
                            break;
                        }
                        else
                        {
                            game[j][3]=1;
                            numlove1=j;
                        }
                    }

                    else if(!strcmp(lover2,names[j]))
                    {
                        if(game[j][2]==0)
                        {
                            cout << names[j] << " is already dead. I can't do anything for him/her." << endl;
                            break;
                        }

                        else
                        {
                            game[j][3]=1;
                            numlove2=j;
                            break;
                        }
                    }
                }
                goddess = true;
                cout << "Now " << lover1 << " and " << lover2 << " are \"LOVERS\"." << endl;
                cout << "  ______________________________________________________________________________________________________________________" << endl;
                cout << endl;
            }
        }

        //Fire(4)
        if(role1[1]==1)
        {
            cout << "Fire! Wanna \"Oil\" or \"Burn\"?" << endl;
            cin >> oil;

            if(!strcmp(oil,"oil") || !strcmp(oil,"Oil"))
            {
                cout << "Who do u wanna oil?"<< endl;
                cin >> oil;
                for(int k=0 ; k<n ; k++)
                {
                    if(!strcmp(oil,names[k]))
                    {
                        if(game[k][2]==0)
                        {
                            cout << names[k] << " is dead. I can't do anything for him/her." << endl;
                            break;
                        }

                        else if(game[k][2]==1 && game[k][5]==1)
                        {
                            cout << "Can't oil " << names[k] << ". He/She is protected by the Guardian Angel." << endl;
                            break;
                        }

                        else if(game[k][5]==0 && game[k][2]==1)
                        {
                            game[k][4]=1;
                            cout << names[k] << " is oiled." << endl;
                            break;
                        }
                    }
                }
                cout << "  ______________________________________________________________________________________________________________________" << endl;
                cout << endl;
            }

            else if(!strcmp(oil,"burn") || !strcmp(oil,"Burn"))
            {
                cout << "Wait to burn all the oily people..."<< endl;
                for(int i=0 ; i<n ; i++)
                {
                    if(game[i][4]==1)
                    {
                        if(game[i][2]==0)
                            cout << names[i] << " is already dead. I can't do anything for him/her." << endl;

                        else if(game[i][5]==1)
                            cout << "Can't kill " << names[i] << ". He/She is protected by the Guardian Angel." << endl;

                        else if(game[i][5]!=1)
                        {
                            game[i][2]=0;
                            role1[game[i][0]]--;
                            alive--;
                            cout << names[i] << " is burnt to ashes and dead. :)" << endl;
                            if(game[i][3]==1)
                            {
                                if(i==numlove1)
                                {
                                    if(game[numlove2][2]==0)
                                        cout << "The lover " << names[numlove2] << " is already dead." << endl;

                                    else
                                    {
                                    game[numlove2][2]=0;
                                    role1[game[i][0]]--;
                                    cout << "Grief made " << names[numlove2] << " to commit suicide. Now " << names[numlove2] << " is dead too." << endl;
                                    alive--;
                                    }
                                }
                                else if(i==numlove2)
                                {
                                    if(game[numlove1][2]==0)
                                       cout << "The lover " << names[numlove1] << " is already dead." << endl;

                                    else
                                    {
                                    game[numlove1][2]=0;
                                    role1[game[i][0]]--;
                                    cout << "Grief made " << names[numlove1] << " to commit suicide. Now " << names[numlove1] << " is dead too." << endl;
                                    alive--;
                                    }
                                }
                            }
                        }
                    }
                }
                cout << "  ______________________________________________________________________________________________________________________" << endl;
                cout << endl;
            }

        }

        //Serial Killer(2)
        if(role1[0]==1)
        {
            cout << "Serial Killer! Who do u wanna to \"Kill\" tonight?" << endl;
            cin >> kill;
            for( int j=0 ; j<n ; j++)
            {
                if(!strcmp(kill,names[j]))
                {
                    if(game[j][2]==0)
                    {
                        cout << names[j] << " is already dead. I can't do anything for him/her." << endl;
                        break;
                    }
                    else if(game[j][5]==1)
                    {
                        cout << "Can't kill " << names[j] << ". He/She is protected by the Guardian Angel." << endl;
                        break;
                    }
                    else if(game[j][5]==0)
                    {
                        game[j][2]=0;
                        role1[game[j][0]]--;
                        alive--;
                        cout << names[j] << "'s dead body found by other villagers drowned in blood." << endl;
                        if(game[j][3]==1)
                        {
                            if(j==numlove1)
                            {
                                if(game[numlove2][2]==0)
                                {
                                    cout << "The lover " << names[numlove2] << " is already dead." << endl;
                                    break;
                                }
                                else
                                {
                                game[numlove2][2]=0;
                                role1[game[j][0]]--;
                                cout << "Grief made " << names[numlove2] << " to commit suicide. Now " << names[numlove2] << " is dead too." << endl;
                                alive--;
                                break;
                                }
                            }
                            else if(j==numlove2)
                            {
                                if(game[numlove1][2]==0)
                                {
                                    cout << " The lover " << names[numlove1] << " is dead." << endl;
                                    break;
                                }
                                else
                                {
                                game[numlove1][2]=0;
                                role1[game[j][0]]--;
                                cout << "Grief made " << names[numlove1] << " to commit suicide. Now " << names[numlove1] << " is dead too." << endl;
                                alive--;
                                break;
                                }
                            }
                        }
                    }
                }
            }
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            cout << endl;
        }

        //Hunter(2)
        if(role1[5]==1)
        {
            cout << "Hunter! Do u wanna \"Hunt\" tonight or \"Rest\"?"<< endl;
            cin >> hunt_or_rest;
            if(!strcmp(hunt_or_rest,"rest") || !strcmp(hunt_or_rest,"Rest"))
            {
                cout << "OK. Rest in bed crazy hunter!" << endl;
                cout << "  ______________________________________________________________________________________________________________________" << endl;
            }
            if(!strcmp(hunt_or_rest,"hunt") || !strcmp(hunt_or_rest,"Hunt"))
            {
                if( numhunt==0)
                {
                    cout << "You are out of bullets!" << endl;
                    break;
                }
                else if(numhunt>0)
                {
                    cout << "Who do u wanna \"Hunt\" down tonight?" << endl;
                    cin >> hunt;
                    for( int k=0 ; k<n ; k++)
                    {
                        if(!strcmp(hunt,names[k]))
                        {
                            if(game[k][2]==0)
                            {
                                cout << names[k] << " is already dead. I can't do anything for him/her." << endl;
                                break;
                            }
                            else if(game[k][0]!=4)
                            {
                                cout << "Can't kill him/her." << names[k] << " is not a cult." << endl;
                                break;
                            }
                            else
                            {

                                if(game[k][5]==1)
                                {
                                    cout << "Can't kill " << names[k] << ". He/She is protected by the Guardian Angel." << endl;
                                    break;
                                }
                                else if(game[k][5]==0)
                                {
                                    game[k][2]=0;
                                    role1[game[k][0]]--;
                                    numhunt--;
                                    alive--;
                                    cout << names[k] << " hunted down and dead." << endl;
                                    if(game[k][3]==1)
                                    {
                                        if(k==numlove1)
                                        {
                                            if(game[numlove2][2]==0)
                                            {
                                                cout << "The lover " << names[numlove2] << " is already dead." << endl;
                                                break;
                                            }
                                            else
                                            {
                                                game[numlove2][2]=0;
                                                role1[game[k][0]]--;
                                                cout << "Grief made " << names[numlove2] << " to commit suicide. Now " << names[numlove2] << " is dead too." << endl;
                                                alive--;
                                                break;
                                            }
                                        }
                                        else if(k==numlove2)
                                        {
                                            if(game[numlove1][2]==0)
                                            {
                                                cout << "The lover " << names[numlove1] << " is already dead." << endl;
                                                break;
                                            }
                                            else
                                            {
                                                game[numlove1][2]=0;
                                                role1[game[k][0]]--;
                                                cout << "Grief made " << names[numlove1] << " to commit suicide. Now " << names[numlove1] << " is dead too." << endl;
                                                alive--;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                cout << "  ______________________________________________________________________________________________________________________" << endl;
            }
            cout << endl;
        }


        //Wolf(2)
        if(role1[6]>0)
        {
            cout << "Wolves! Who do u wanna \"Eat\" tonight?" << endl;
            cin >> eat;
            for( int i=0 ; i<n ; i++)
            {
                if(!strcmp(eat,names[i]))
                {
                    if(game[i][2]==0)
                    {
                        cout << names[i] << " is already dead. I can't do anything for him/her." << endl;
                        break;
                    }
                    else if(game[i][5]==1)
                    {
                        cout << "Can't kill " << names[i] << ". He/She is protected by the Guardian Angel." << endl;
                        break;
                    }
                    else if(game[i][5]==0)
                    {
                        game[i][2]=0;
                        role1[game[i][0]]--;
                        alive--;
                        cout << names[i] << "'s dead body found in woods. " << names[i] << " was eaten by wolves." << endl;
                        if(game[i][3]==1)
                        {
                            if(i==numlove1)
                            {
                                if(game[numlove2][2]==0)
                                {
                                    cout << "The lover "<< names[numlove2] << " is already dead." << endl;
                                    break;
                                }
                                else
                                {
                                game[numlove2][2]=0;
                                role1[game[i][0]]--;
                                cout << "Grief made " << names[numlove2] << " to commit suicide. Now " << names[numlove2] << " is dead too." << endl;
                                alive--;
                                break;
                                }
                            }
                            else if(i==numlove2)
                            {
                                if(game[numlove1][2]==0)
                                {
                                    cout << "The lover " << names[numlove1] << " is alredy dead." << endl;
                                    break;
                                }
                                else
                                {
                                game[numlove1][2]=0;
                                role1[game[i][0]]--;
                                cout << "Grief made " << names[numlove1] << " to commit suicide. Now " << names[numlove1] << " is dead too." << endl;
                                alive--;
                                break;
                                }
                            }
                        }
                    }
                }
            }
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            cout << endl;
        }


        //Cult(0)
        if(role1[4]>0)
        {
            cout << "Cult! Who do u wanna \"Invite?\"" << endl;
            cin >> cult;
            for( int j=0 ; j<n ; j++)
            {
                if(!strcmp(cult,names[j]))
                {
                    if(game[j][2]==0)
                    {
                        cout << names[j] << " is already dead. I can't do anything for him/her." << endl;
                        break;
                    }
                    else if(game[j][0]==5)
                    {
                        cout << "Can't invite him/her." << names[j] << " is the hunter." << endl;
                        break;
                    }
                    else
                    {
                        role1[game[j][0]]--;
                        role1[4]++;
                        game[j][0]=4;                    
                        cout << names[j] << " is invited to the cult." << endl;
                        break;
                    }
                }
            }
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            cout << endl;
        }


        //Result after night
        for( int k=0 ; k<n ; k++)
        {
            if(game[k][2]==0)
                cout << names[k] << "\t" << "\"Dead\"" << "\t" << "#-#" <<endl;

            else if (game[k][2]==1)
                cout << names[k] << "\t" << "\"Alive\"" << "\t" << roles[game[k][0]] << endl;
        }
        cout << "\a" << "  ______________________________________________________________________________________________________________________" << endl;
        cout << endl;


        //Winnig conditions
        if( alive<=2 && role1[1]==1)
        {
            cout << "Fire \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }
        else if( alive<=2 && role1[0]==1)
        {
            cout << "Serial Killer \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }
        else if( alive<=2 && role1[6]==1)
        {
            cout << "Wolf \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }
        else if( alive>2 && (role1[6]> role1[7]) && role1[1]==0 && role1[0]==0)
        {
            cout << "Wolf \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }
        else if( alive>2 && (alive == role1[4]))
        {
            cout << "Cult \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }
        else if( alive>2 && (role1[1]==0 && role1[0]==0 && role1[4]))
        {
            cout << "Villagers \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }

        //Vote(1)
        cout << "Goodmornig!. Wake up everybody!" << endl;
        cout << endl;
        cout << endl;
        cout << "Guys time to vote!!" << endl;
        cout << endl;

        for( int i=0 ; i<n ; i++)
        {
            if(game[i][2]==1)
            {
                cout << "Gimme the number of votes for " << names[i] << " : ";
                cin >> votes[i];
                cout << endl;
                game[i][1]= votes[i];
            }
        }


        //Calc votes

        bool sort = false;
        while(sort==false)
        {
            sort = true;
            for( int j=0 ; j<n-1 ; j++ )
            {
                if(votes[j] < votes[j+1])
                {
                    int temp = votes[j];
                    votes[j] = votes[j+1];
                    votes[j+1] = temp;
                    sort = false;
                }
            }
        }

        for( int k=0 ; k<n ; k++)
        {
            if(votes[0]==votes[1])
            {
                cout << "Take a deep breath nobody dies today!" << endl;
                cout << "  ______________________________________________________________________________________________________________________" << endl;
                break;
            }
            else if( game[k][2]==1)
            {
                if( game[k][1]==votes[0])
                {
                    game[k][2]=0;
                    role1[game[k][0]]--;
                    alive--;
                    cout << names[k] << " with " << votes[0] << " votes kicked out successfully." << endl;
                    if(game[k][3]==1)
                    {
                        if(k==numlove1)
                        {
                            if(game[numlove2][2]==0)
                            {
                                cout << "The lover "<< names[numlove2] << " is already dead." << endl;
                                cout << "  ______________________________________________________________________________________________________________________" << endl;
                                break;
                            }
                            else
                            {
                            game[numlove2][2]=0;
                            cout << "Grief made " << names[numlove2] << " to commit suicide. Now " << names[numlove2] << " is dead too." << endl;
                            alive--;
                            cout << "  ______________________________________________________________________________________________________________________" << endl;
                            break;
                            }
                        }
                        else if(k==numlove2)
                        {
                            if(game[numlove1][2]==0)
                            {
                                cout << "The lover " << names[numlove1] << " is alredy dead." << endl;
                                cout << "  ______________________________________________________________________________________________________________________" << endl;
                                break;
                            }
                            else
                            {
                            game[numlove1][2]=0;
                            cout << "Grief made " << names[numlove1] << " to commit suicide. Now " << names[numlove1] << " is dead too." << endl;
                            cout << "  ______________________________________________________________________________________________________________________" << endl;
                            alive--;
                            break;
                            }
                        }
                    }
                    cout << "  ______________________________________________________________________________________________________________________" << endl;
                }
            }
        }
        cout << endl;

        //Result after vote
        for( int k=0 ; k<n ; k++)
        {
            if(game[k][2]==0)
                cout << names[k] << "\t" << "\"Dead\"" << "\t" << "#-#" <<endl;

            else if (game[k][2]==1)
                cout << names[k] << "\t" << "\"Alive\"" << "\t" << roles[game[k][0]] << endl;
        }
        cout << "\a" << "  ______________________________________________________________________________________________________________________" << endl;
        cout << endl;


        //Remove previous votes
        for( int i=0 ; i<n ; i++)
            votes[i]=0;


        //Winnig conditions
        if( alive<=2 && role1[1]==1)
        {
            cout << "Fire \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }
        if( alive<=2 && role1[0]==1)
        {
            cout << "Serial Killer \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }
        if( alive<=2 && role1[6]==1)
        {
            cout << "Wolf \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }
        if( alive>2 && (role1[6]> role1[7]) && (role1[6]> role1[4]) && role1[1]==0 && role1[0]==0)
        {
            cout << "Wolf \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }
        if( alive>2 && (alive == role1[4]))
        {
            cout << "Cult \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }
        if( alive>2 && (role1[1]==0 && role1[0]==0 && role1[4]))
        {
            cout << "Villagers \"WON THE GAME\"" << endl;
            cout << "  ______________________________________________________________________________________________________________________" << endl;
            break;
        }

        //Remove previous protection
        for( int i=0 ; i<n ; i++)
        {
            game[i][5]=0;
        }

    }

    cout << "\a" << "Well Done. See you next round." << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout <<"                               __" << endl;
    cout <<"                             .d$$b " << endl;
    cout <<"                           .' TO$;\ " << endl;
    cout <<"                          /  : TP._;" << endl;
    cout <<"                         / _.;  :Tb|" << endl;
    cout <<"                        /   /   ;j$j" << endl;
    cout <<"                   _.-\"       d$$$$" << endl;
    cout <<"                  .' ..       d$$$$;" << endl;
    cout <<"                 /  /P'      d$$$$P. |\ " << endl;
    cout <<"                /   \"      .d$$$P' |\^\"l" << endl;
    cout <<"              .'           `T$P^\"\"\"\"\"  :" << endl;
    cout <<"          ._.'      _.'                ;" << endl;
    cout <<"       `-.-\".-'-' ._.       _.-\"    .-\"" << endl;
    cout <<"     `.-\" _____  ._              .-\"" << endl;
    cout <<"    -(.g$$$$$$$b.              .'" << endl;
    cout <<"      \"\"^^T$$$P^)            .(:" << endl;
    cout <<"        _/  -\"  /.'         /:/;" << endl;
    cout <<"     ._.'-'`-'  \")/         /;/;" << endl;
    cout <<"  `-.-\"..--\"\"   \" /         /  ;" << endl;
    cout <<" .-\" ..--\"\"        -'          :" << endl;
    cout <<" ..--\"\"--.-\"         (\      .-(\ " << endl;
    cout <<"   ..--\"\"              `-\(\/;`" << endl;
    cout <<"     _.                      :" << endl;
    cout <<"                             ;`-" << endl;
    cout <<"                            :\ " << endl;
    cout <<"                            ;  " << endl;
    return 0;
}
