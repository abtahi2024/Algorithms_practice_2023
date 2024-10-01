// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int num = 1;
//     int space_begin = 0;
//     int space_mid = (n * 2) - 3;

//     for (int i = 1; i <= (n * 2) - 1; i++)
//     {
//         for (int j = 0; j < space_begin; j++)
//         {
//             cout << " ";
//         }
//         cout << num;
//         for (int j = 0; j < space_mid; j++)
//         {
//             cout << " ";
//         }
//         if (i != n)
//         {
//             cout << num;
//         }

//         cout << endl;

//         if (num == 0 || num == 1)
//         {
//             num++;
//         }
//         else
//         {
//             num = 0;
//         }

//         if (i < n)
//         {
//             space_begin++;
//             space_mid -= 2;
//         }
//         else if (i >= n)
//         {
//             space_begin--;
//             space_mid += 2;
//         }
//     }

//     return 0;
// }





// // 1   1
// //  2 2
// //   0
// //  1 1
// // 2   2


// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
    
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             cout<<" ";
            
//         }
//         cout<<i;
//         for(int j=0;j<2*(n-i-1)-1;j++)
//         {
//             cout<<" ";
//         }
//         if(i<n-1)
//         {
//             cout<<i;
//         }
//         cout<<endl;
//     }
//     for(int i=n-2;i>=0;i--)
//     {
//         for(int j=0;j<i;j++)
//         {
//             cout<<" ";
//         }
//         cout<<i;
//         for(int j=0;j<2*(n-i-1)-1;j++)
//         {
//             cout<<" ";
//         }
//         if(i<n-1)
//         {
//             cout<<i;
//         }
//         cout<<endl;
//     }
  


//     return 0;
// }

