#include <iostream>
#include <map>
#include <iterator>
using namespace std;
 
int main() 
{
    std:: multimap <string,map <string,int> > Weather;
    int n, op;

    cout << "Enter Number of Entries: ";
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        string city;
        string date;
        int temp;
        cout << "Entry " << i+1 << endl;
        cout << "Enter City: ";
        cin >> city;
        cout << "Enter Date: ";
        cin >> date;
        cout << "Enter Temperature: ";
        cin >> temp;
        std:: map <string,int> Wd;
        Wd.emplace(date,temp);
        Weather.emplace(city,Wd);
    }

    std::multimap<string, map<string,int> >::iterator it;
    std::map<string,int>::iterator it1;

    string city1;
    string date1;
    string city2;
    int max = 0;
    menu:;
    cout << "\n";
    cout << "Menu: " << endl;
    cout << "1. Display all Data Recorded" << endl;
    cout << "2. Searching Data Based on City & Date" << endl;
    cout << "3. To Find Maximum Recorded Temperature of a city" << endl;
    cout << "4. Deleting Record of a city" << endl;
    cout << "5. Deleting Particular Record of City " << endl;
    cout << "6. End" << endl;
    cout << "Enter Option: ";
    cin >> op;

    switch(op)
    {
        case 1:
                system("clear");
                cout << "\nData is:\n";
                cout << "City\t\tDate\t\tTemperature" << endl;
                for(it=Weather.begin();it != Weather.end();it++)
                {
                    for(it1 = it -> second.begin();it1 != it -> second.end();it1++)
                    {
                        cout << it -> first << "\t\t";
                        cout << it1 -> first << "\t\t";
                        cout << it1 -> second << "\t";
                        cout << endl;
                    }
                }
                goto menu;

        case 2:
                system("clear");
                cout << "Enter City: ";
                cin >> city1; 
                cout << "Enter Date: ";
                cin >> date1;   

                for(it=Weather.begin();it != Weather.end();it++)
                {
                    if(it -> first == city1)
                    {
                        for(it1 = it->second.begin();it1 != it->second.end();it1++)
                        {
                            if(it1->first == date1)
                            {
                                cout << it -> first << " ";
                                cout << it1 -> first << " ";
                                cout << it1 -> second << " ";
                            }
                        }
                        cout << endl;
                    }      
                }
                goto menu;

        case 3:
                system("clear");
                max = 0;
                cout << "Enter City: ";
                cin >> city2;
                for(it=Weather.begin();it != Weather.end();it++)
                {
                    if(it -> first == city2)
                    {
                        for(it1 = it->second.begin();it1 != it->second.end();it1++)
                        {
                          if(it1 -> second > max)
                          {
                            max = it1 -> second;
                          }
                        }
                        cout << endl;
                    }
                }
                cout<< "Maximum Temperature Recorded for "<<city2<<" is "<<max;
                goto menu;

        case 4:
                system("clear");
                max = 0;
                cout << "Enter City: ";
                cin >> city2;
                Weather.erase(city2);
                cout << " Record of " << city2 << " Deleted "<< endl;
                goto menu;

        case 5:
                system("clear");
                cout << "Enter City: ";
                cin >> city1; 
                cout << "Enter Date: ";
                cin >> date1;   

                for(it=Weather.begin();it != Weather.end();it++)
                {
                    if(it -> first == city1)
                    {
                        for(it1 = it->second.begin();it1 != it->second.end();it1++)
                        {
                            if(it1->first == date1)
                            {
                                (it->second).erase(date1);
                            }
                        }
                        cout << endl;
                    }      
                }
                goto menu;
        case 6:
                break;
    }

    return 0;
#include <iostream>
#include <map>
#include <iterator>
using namespace std;
 
int main() 
{
    std:: multimap <string,map <string,int> > Weather;
    int n, op;

    cout << "Enter Number of Entries: ";
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        string city;
        string date;
        int temp;
        cout << "Entry " << i+1 << endl;
        cout << "Enter City: ";
        cin >> city;
        cout << "Enter Date: ";
        cin >> date;
        cout << "Enter Temperature: ";
        cin >> temp;
        std:: map <string,int> Wd;
        Wd.emplace(date,temp);
        Weather.emplace(city,Wd);
    }

    std::multimap<string, map<string,int> >::iterator it;
    std::map<string,int>::iterator it1;

    string city1;
    string date1;
    string city2;
    int max = 0;
    menu:;
    cout << "\n";
    cout << "Menu: " << endl;
    cout << "1. Display all Data Recorded" << endl;
    cout << "2. Searching Data Based on City & Date" << endl;
    cout << "3. To Find Maximum Recorded Temperature of a city" << endl;
    cout << "4. Deleting Record of a city" << endl;
    cout << "5. Deleting Particular Record of City " << endl;
    cout << "6. End" << endl;
    cout << "Enter Option: ";
    cin >> op;

    switch(op)
    {
        case 1:
                system("clear");
                cout << "\nData is:\n";
                cout << "City\t\tDate\t\tTemperature" << endl;
                for(it=Weather.begin();it != Weather.end();it++)
                {
                    for(it1 = it -> second.begin();it1 != it -> second.end();it1++)
                    {
                        cout << it -> first << "\t\t";
                        cout << it1 -> first << "\t\t";
                        cout << it1 -> second << "\t";
                        cout << endl;
                    }
                }
                goto menu;

        case 2:
                system("clear");
                cout << "Enter City: ";
                cin >> city1; 
                cout << "Enter Date: ";
                cin >> date1;   

                for(it=Weather.begin();it != Weather.end();it++)
                {
                    if(it -> first == city1)
                    {
                        for(it1 = it->second.begin();it1 != it->second.end();it1++)
                        {
                            if(it1->first == date1)
                            {
                                cout << it -> first << " ";
                                cout << it1 -> first << " ";
                                cout << it1 -> second << " ";
                            }
                        }
                        cout << endl;
                    }      
                }
                goto menu;

        case 3:
                system("clear");
                max = 0;
                cout << "Enter City: ";
                cin >> city2;
                for(it=Weather.begin();it != Weather.end();it++)
                {
                    if(it -> first == city2)
                    {
                        for(it1 = it->second.begin();it1 != it->second.end();it1++)
                        {
                          if(it1 -> second > max)
                          {
                            max = it1 -> second;
                          }
                        }
                        cout << endl;
                    }
                }
                cout<< "Maximum Temperature Recorded for "<<city2<<" is "<<max;
                goto menu;

        case 4:
                system("clear");
                max = 0;
                cout << "Enter City: ";
                cin >> city2;
                Weather.erase(city2);
                cout << " Record of " << city2 << " Deleted "<< endl;
                goto menu;

        case 5:
                system("clear");
                cout << "Enter City: ";
                cin >> city1; 
                cout << "Enter Date: ";
                cin >> date1;   

                for(it=Weather.begin();it != Weather.end();it++)
                {
                    if(it -> first == city1)
                    {
                        for(it1 = it->second.begin();it1 != it->second.end();it1++)
                        {
                            if(it1->first == date1)
                            {
                                (it->second).erase(date1);
                            }
                        }
                        cout << endl;
                    }      
                }
                goto menu;
        case 6:
                break;
    }

    return 0;
}