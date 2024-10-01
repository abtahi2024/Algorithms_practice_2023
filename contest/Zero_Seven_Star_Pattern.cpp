#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>> n;
    if(n%2!=0)
    {
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"0";
        }
        cout<<"*";
        for(int j=0;j<n-2*i-2;j++)
        {
            cout<<"7";
        }
        cout<<"*";
        for(int j=0;j<i;j++)
        {
            cout<<"7";
        }
        cout<<endl;
    }
    for(int i=0;i<n/2;i++)
    {
        cout<<"0";
        
    }
    cout<<"*";

    
    for(int i=0;i<n/2;i++)
    {
        cout<<"7";
    }
    cout<<endl;
    for(int i=n/2-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"0";
        }
        cout<<"*";

        for(int j=0;j<n-2*i-2;j++)
        {
            cout<<"0";
        }
        cout<<"*";
        for(int j=0;j<i;j++)
        {
            cout<<"7";
        }
        cout<<endl;
    }
}
    else
    {
       for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"0";
        }
        cout<<"*";
        for(int j=0;j<n-2*i-2;j++)
        {
            cout<<"7";
        }
        cout<<"*";
        for(int j=0;j<i;j++)
        {
            cout<<"7";
        }
        cout<<endl;
    }
    
    for(int i=n/2-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"0";
        }
        cout<<"*";

        for(int j=0;j<n-2*i-2;j++)
        {
            cout<<"0";
        }
        cout<<"*";
        for(int j=0;j<i;j++)
        {
            cout<<"7";
        }
        cout<<endl;
    }
    }

    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     if (n % 2 != 0) {
//         for (int i = 0; i < n / 2; i++) {
//             for (int j = 0; j < i; j++) {
//                 cout << "0";
//             }
//             cout << "*";
//             for (int j = 0; j < n - 2 * i - 2; j++) {
//                 cout << "7";
//             }
//             cout << "*";
//             for (int j = 0; j < i; j++) {
//                 cout << "7";
//             }
//             cout << endl;
//         }
//         for (int i = 0; i < n / 2; i++) {
//             cout << "0";
//         }
//         cout << "*";
//         for (int i = 0; i < n / 2; i++) {
//             cout << "7";
//         }
//         cout << endl;
//         for (int i = n / 2 - 1; i >= 0; i--) {
//             for (int j = 0; j < i; j++) {
//                 cout << "0";
//             }
//             cout << "*";
//             for (int j = 0; j < n - 2 * i - 2; j++) {
//                 cout << "0";
//             }
//             cout << "*";
//             for (int j = 0; j < i; j++) {
//                 cout << "7";
//             }
//             cout << endl;
//         }
//     } else {
//         for (int i = 0; i < n / 2; i++) {
//             for (int j = 0; j < i; j++) {
//                 cout << "0";
//             }
//             cout << "*";
//             for (int j = 0; j < n - 2 * i - 2; j++) {
//                 cout << "7";
//             }
            
//             cout << "*";
//             for (int j = 0; j < i; j++) {
//                 cout << "7";
                
//             }
//             cout<<endl;
            
//         }
      
//         for (int i = n / 2 - 1; i >= 0; i--) {
//             for (int j = 0; j < i; j++) {
//                 cout << "0";
//             }
//             cout << "*";
//             for (int j = 0; j < n - 2 * i - 2; j++) {
//                 cout << "0";
//             }
//             cout << "*";
//             for (int j = 0; j < i; j++) {
//                 cout << "7";
//             }
//             cout << endl;
//         }
//     }

//     return 0;
// }
