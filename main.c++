#include <bits/stdc++.h>
using namespace std;
int sdes_encryption()
{
    bool pt[9];
    bool k1[9];
    bool k2[9];
    int ip[9]={0,2,6,3,1,4,8,5,7};
    int fp[9]={0,4,1,3,5,7,2,8,6};
    int epb[9]={0,4,1,2,3,2,3,4,1};
    int spb[5]={0,2,4,3,1};
    int s1[4][4]={{1,0,3,2},
                  {3,2,1,0},
                  {0,2,1,3},
                  {3,1,3,2}};
    int s2[4][4]={{0,1,2,3},
                  {2,0,1,3},
                  {3,0,1,0},
                  {2,1,0,3}};
    bool ipout[9];
    bool fpout[9];
    bool eout[9];
    bool eout2[9];
    bool Xor[9];
    bool Xor2[9];
    bool spbo[5];
    bool spbo2[5];
    bool S[5];
    bool S2[5];
    bool xsbpip[5];
    bool xsbpip2[5];
    bool XorL[4];
    bool B[4];
    bool B2[4];
    bool A[4];
    bool C[9];
    bool C2[9];
    bool P2[9];
    int i,r1,r2,r3,r4,col1,col2,col3,col4,s1out,s2out,s3out,s4out;

    cout<<"---------------------Enter plaintext :----------------------- \n";
    for(i=0;i<9;i++)
    {
        cin>>pt[i];
    }
//-----------------------------------------------------------------

    cout<<"---------------------The plaintext is :----------------------- \n";
    for(i=1;i<9;i++)
    {
        cout<<pt[i]<<" ";
    }
//-----------------------------------------------------------------
    cout<<"\n---------------------Enter K1 :----------------------- \n";
    for(i=0;i<9;i++)
    {
        cin>>k1[i];
    }

//-----------------------------------------------------------------

    cout<<"---------------------the K1 is :----------------------- \n";
    for(i=1;i<9;i++)
    {
        cout<<k1[i]<<" ";
    }

//-----------------------------------------------------------------
    cout<<"\n---------------------Enter K2 :----------------------- \n";
    for(i=0;i<9;i++)
    {
        cin>>k2[i];
    }

//-----------------------------------------------------------------

    cout<<"---------------------the K2 is :----------------------- \n";
    for(i=1;i<9;i++)
    {
        cout<<k2[i]<<" ";
    }


//-----------------------------------------------------------------
    cout<<"\n------------------after Initial permutation :---------------- \n";

    for (i=1;i<9;i++)
    {
        ipout[i]=pt[ip[i]];
    }

    for(i=1;i<9;i++)
    {
        cout<<ipout[i]<<" ";
    }
//------------------------------------------------------------------
    cout<<"\n-----------------after expension p box------------------------\n";

    for (i=1;i<9;i++)
    {
        int a=0;
        a=epb[i];
        eout[i]=ipout[5+a-1];
    }

    for (i=1;i<9;i++)
    {
        cout<<eout[i]<<" ";
    }
//----------------------------------------------------------------------

    for (i=1;i<9;i++)
    {
        if(eout[i] == k1[i])
        {
            Xor[i]=0;
        }
        else
        {
            Xor[i]=1;
        }
    }
    cout<<"\n\n----------the result of expansion p box and k1 xor is :---------- \n";
    for (i=1;i<9;i++)
    {
        cout<<Xor[i]<<" ";
    }
//---------------------------------------------------------------------------------//
    cout <<"\n\n-----------------s box 1----------\n";
    cout<<"\nthe row is : ";
    r1=((2*Xor[1])+Xor[4]);
    cout << r1;

    cout<<"\nthe coloumn is : ";
    col1=((2*Xor[2])+Xor[3]);
    cout <<col1;

    cout<<"\nthe value on s box 1 is : ";
    s1out=s1[r1][col1];
    cout<<s1out<<endl;
    B[0]=0;
    B[1]=s1out / 2;
    B[2]=s1out % 2;

    cout <<"\n the s1 box output in binary : ";
    for (i=1;i<3;i++)
    {
        cout<<B[i]<<" ";
    }
//--------------------------------------------------------------
    cout <<"\n-----------------s box 2----------\n";
    cout<<"\nthe row is : ";
    r2=((2*Xor[5])+Xor[8]);
    cout << r2;

    cout<<"\nthe coloumn is : ";
    col2=((2*Xor[6])+Xor[7]);
    cout <<col2;

    cout<<"\nthe value on s box 2 is : ";
    s2out=s2[r2][col2];
    cout<<s2out<<endl;

    B[3]=s2out / 2;
    B[4]=s2out % 2;

    cout <<"\n the s2 box output in binary : ";
    for (i=3;i<5;i++)
    {
        cout<<B[i]<<" ";
    }
    //----------------------------------------------------------------------
    cout<<"\n-----------------result s boxes----------\n";
    cout<<"\ncombining s1 box and s2 box output :\n";
    for (i=1;i<5;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    for (i=1;i<5;i++)
    {
        S[i]=B[i];
    }

//----------------------------------------------------------------------------
    cout <<"\n-----------------result straight p box----------\n";

    for (i=1;i<5;i++)
    {
        spbo[i]=S[spb[i]];
    }

    for (i=1;i<5;i++)
    {
        cout<<spbo[i]<<" ";
    }
//------------------------------------------------------------------
    cout <<"\n-----------------result straight p box output XOR with left 4 bits of ip box output----------\n";
    for (i=1;i<5;i++)
    {
        if (ipout[i]==spbo[i])
        {
            xsbpip[i]=0;
        }
        else
        {
            xsbpip[i]=1;
        }
    }

    for (i=1;i<5;i++)
    {
        cout<<xsbpip[i]<<" ";
    }

//-------------------------------------------------------------------------------------------------
    cout <<"\n-----------------combining the xor result and ipout right 4 bits : ----------\n";
    for (i=1;i<5;i++)
    {
        C[i]=xsbpip[i];
    }
    for (i=5;i<9;i++)
    {
        C[i]=ipout[i];
    }
    for (i=1;i<9;i++)
    {
        cout<<C[i]<<" ";
    }
//------------------------------------------------------------------------------------
    cout <<"\n-----------------swapper output : ----------\n";
    for (i=1;i<5;i++)
    {
        P2[i]=C[i+4];
    }

    for (i=5;i<9;i++)
    {
        P2[i]=C[i-4];
    }

    for (i=1;i<9;i++)
    {
        cout<<P2[i]<<" ";
    }

    ///////////////////// round 2

    //------------------------------------------------------------------
    cout<<"\n\n--------------- round 2 expension p box------------------ \n";

    for (i=1;i<9;i++)
    {
        int a=0;
        a=epb[i];
        eout2[i]=P2[5+a-1];
    }

    for (i=1;i<9;i++)
    {
        cout<<eout2[i]<<" ";
    }
//----------------------------------------------------------------------
    cout<<"\n\n-----------------the result of round 2 expansion p box and k2 xor is :---------------------- \n";
    for (i=1;i<9;i++)
    {
        if(eout2[i] == k2[i])
        {
            Xor2[i]=0;
        }
        else
        {
            Xor2[i]=1;
        }
    }

    for (i=1;i<9;i++)
    {
        cout<<Xor2[i]<<" ";
    }
//-------------------------------------------------------------------------------------------------------------
    cout <<"\n\n-----------------s box 1 of round 2----------\n";
    cout<<"\nthe row is : ";
    r3=((2*Xor2[1])+Xor2[4]);
    cout << r3;

    cout<<"\nthe coloumn is : ";
    col3=((2*Xor2[2])+Xor2[3]);
    cout <<col3;

    cout<<"\nthe value on s box 1 is : ";
    s3out=s1[r3][col3];
    cout<<s3out<<endl;
    B2[0]=0;
    B2[1]=s3out / 2;
    B2[2]=s3out % 2;

    cout <<"\n---------------the s1 box output in binary :------------- : \n";
    for (i=1;i<3;i++)
    {
        cout<<B2[i]<<" ";
    }
//---------------------------------------------------------------------------------------------

    cout <<"\n-----------------round 2 s box 2----------\n";
    cout<<"\nthe row is : ";
    r4=((2*Xor2[5])+Xor2[8]);
    cout << r4;

    cout<<"\nthe coloumn is : ";
    col4=((2*Xor2[6])+Xor2[7]);
    cout <<col4;

    cout<<"\nthe value on s box 1 is : ";
    s4out=s2[r4][col4];
    cout<<s4out<<endl;

    B2[3]=s4out / 2;
    B2[4]=s4out % 2;

    cout <<"\n the s2 box output in binary : ";
    for (i=3;i<5;i++)
    {
        cout<<B2[i]<<" ";
    }

    //----------------------------------------------------------------------
    cout <<"\n-----------------result of round 2 s boxes----------\n";
    cout<<"\ncombining s1 box and s2 box output :\n";
    for (i=1;i<5;i++)
    {
        cout<<B2[i]<<" ";
    }
    cout<<endl;
    for (i=1;i<5;i++)
    {
        S2[i]=B2[i];
    }

//----------------------------------------------------------------------------
    cout <<"\n-----------------result of round 2 straight p box----------\n";

    for (i=1;i<5;i++)
    {
        spbo2[i]=S2[spb[i]];
    }

    for (i=1;i<5;i++)
    {
        cout<<spbo2[i]<<" ";
    }
//------------------------------------------------------------------
    cout <<"\n-----------------result straight p box of round 2 output XOR with left 4 bits of round 1 output----------\n";
    for (i=1;i<5;i++)
    {
        if (P2[i]==spbo2[i])
        {
            xsbpip2[i]=0;
        }
        else
        {
            xsbpip2[i]=1;
        }
    }

    for (i=1;i<5;i++)
    {
        cout<<xsbpip2[i]<<" ";
    }

//-------------------------------------------------------------------------------------------------
    cout <<"\n-----------------combining the xor result and P2 right 4 bits : ----------\n";
    for (i=1;i<5;i++)
    {
        C2[i]=xsbpip2[i];
    }
    for (i=5;i<9;i++)
    {
        C2[i]=P2[i];
    }
    for (i=1;i<9;i++)
    {
        cout<<C2[i]<<" ";
    }
//------------------------------------------------------------------------------------

    cout<<"\n------------------after final permutation :---------------- \n";
    cout<<"\n------------------the ciphertext for given plaintext is :---------------- \n";

    for (i=1;i<9;i++)
    {
        fpout[i]=C2[fp[i]];
    }

    for(i=1;i<9;i++)
    {
        cout<<fpout[i]<<" ";
    }
    cout<<endl;
}

int sdes_decryption()
{
    int i,r1,r2,r3,r4,col1,col2,col3,col4,s1out,s2out,s3out,s4out;
    bool ct[9];
    bool k1[9];
    bool k2[9];
    int ip[9]={0,2,6,3,1,4,8,5,7};
    bool ipout[9];
    int fp[9]={0,4,1,3,5,7,2,8,6};
    bool fpout[9];
    int epb[9]={0,4,1,2,3,2,3,4,1};
    bool eout[9];
    bool eout2[9];
    bool Xor2[9];
    int spb[5]={0,2,4,3,1};
    int s1[4][4]={{1,0,3,2},
                  {3,2,1,0},
                  {0,2,1,3},
                  {3,1,3,2}};
    int s2[4][4]={{0,1,2,3},
                  {2,0,1,3},
                  {3,0,1,0},
                  {2,1,0,3}};
    bool P2[9];
    bool B[4];
    bool B2[4];
    bool C[9];
    bool C2[9];
    bool S[4];
    bool S2[4];
    bool spbo[5];
    bool spbo2[5];
    bool xsbpip[5];
    bool xsbpip2[5];
    cout<<"---------------------Enter ciphertext :----------------------- \n";
    for(i=0;i<9;i++)
    {
        cin>>ct[i];
    }
//-----------------------------------------------------------------

    cout<<"---------------------The Ciphertext is :----------------------- \n";
    for(i=1;i<9;i++)
    {
        cout<<ct[i]<<" ";
    }
//-----------------------------------------------------------------
    cout<<"\n---------------------Enter K1 :----------------------- \n";
    for(i=0;i<9;i++)
    {
        cin>>k1[i];
    }

//-----------------------------------------------------------------

    cout<<"---------------------the K1 is :----------------------- \n";
    for(i=1;i<9;i++)
    {
        cout<<k1[i]<<" ";
    }

//-----------------------------------------------------------------
    cout<<"\n---------------------Enter K2 :----------------------- \n";
    for(i=0;i<9;i++)
    {
        cin>>k2[i];
    }

//-----------------------------------------------------------------

    cout<<"---------------------the K2 is :----------------------- \n";
    for(i=1;i<9;i++)
    {
        cout<<k2[i]<<" ";
    }

//-----------------------------------------------------------------
    cout<<"\n------------------after Initial permutation :---------------- \n";

    for (i=1;i<9;i++)
    {
        ipout[i]=ct[ip[i]];
    }

    for(i=1;i<9;i++)
    {
        cout<<ipout[i]<<" ";
    }
//------------------------------------------------------------------
    cout<<"\n-----------------after expension p box------------------------\n";

    for (i=1;i<9;i++)
    {
        int a=0;
        a=epb[i];
        eout[i]=ipout[5+a-1];
    }

    for (i=1;i<9;i++)
    {
        cout<<eout[i]<<" ";
    }
//----------------------------------------------------------------------
    for (i=1;i<9;i++)
    {
        if(eout[i] == k2[i])
        {
            Xor2[i]=0;
        }
        else
        {
            Xor2[i]=1;
        }
    }
    cout<<"\n\n----------the result of expansion p box and k2 xor is :---------- \n";
    for (i=1;i<9;i++)
    {
        cout<<Xor2[i]<<" ";
    }
//---------------------------------------------------------------------------------//
    cout <<"\n\n-----------------s box 1----------\n";
    cout<<"\nthe row is : ";
    r1=((2*Xor2[1])+Xor2[4]);
    cout << r1;

    cout<<"\nthe coloumn is : ";
    col1=((2*Xor2[2])+Xor2[3]);
    cout <<col1;

    cout<<"\nthe value on s box 1 is : ";
    s1out=s1[r1][col1];
    cout<<s1out<<endl;
    B[0]=0;
    B[1]=s1out / 2;
    B[2]=s1out % 2;

    cout <<"\n the s1 box output in binary : ";
    for (i=1;i<3;i++)
    {
        cout<<B[i]<<" ";
    }
//--------------------------------------------------------------
    cout <<"\n-----------------s box 2----------\n";
    cout<<"\nthe row is : ";
    r2=((2*Xor2[5])+Xor2[8]);
    cout << r2;

    cout<<"\nthe coloumn is : ";
    col2=((2*Xor2[6])+Xor2[7]);
    cout <<col2;

    cout<<"\nthe value on s box 2 is : ";
    s2out=s2[r2][col2];
    cout<<s2out<<endl;

    B[3]=s2out / 2;
    B[4]=s2out % 2;

    cout <<"\n the s2 box output in binary : ";
    for (i=3;i<5;i++)
    {
        cout<<B[i]<<" ";
    }
    //----------------------------------------------------------------------

    cout <<"\n-----------------result s boxes----------\n";
    cout<<"\ncombining s1 box and s2 box output :\n";
    for (i=1;i<5;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    for (i=1;i<5;i++)
    {
        S[i]=B[i];
    }

//----------------------------------------------------------------------------
    cout <<"\n-----------------result straight p box----------\n";

    for (i=1;i<5;i++)
    {
        spbo[i]=S[spb[i]];
    }

    for (i=1;i<5;i++)
    {
        cout<<spbo[i]<<" ";
    }

    //------------------------------------------------------------------
    cout <<"\n-----------------result straight p box output XOR with left 4 bits of ip box output----------\n";
    for (i=1;i<5;i++)
    {
        if (ipout[i]==spbo[i])
        {
            xsbpip[i]=0;
        }
        else
        {
            xsbpip[i]=1;
        }
    }

    for (i=1;i<5;i++)
    {
        cout<<xsbpip[i]<<" ";
    }

//-------------------------------------------------------------------------------------------------
    cout <<"\n-----------------combining the xor result and ipout right 4 bits : ----------\n";
    for (i=1;i<5;i++)
    {
        C[i]=xsbpip[i];
    }
    for (i=5;i<9;i++)
    {
        C[i]=ipout[i];
    }
    for (i=1;i<9;i++)
    {
        cout<<C[i]<<" ";
    }

//------------------------------------------------------------------------------------
    cout <<"\n-----------------swapper output : ----------\n";
    for (i=1;i<5;i++)
    {
        C2[i]=C[i+4];
    }

    for (i=5;i<9;i++)
    {
        C2[i]=C[i-4];
    }

    for (i=1;i<9;i++)
    {
        cout<<C2[i]<<" ";
    }

    ///////////////////// round 2

    //------------------------------------------------------------------
    cout<<"\n\n--------------- round 2 expension p box------------------ \n";

    for (i=1;i<9;i++)
    {
        int a=0;
        a=epb[i];
        eout2[i]=C2[5+a-1];
    }

    for (i=1;i<9;i++)
    {
        cout<<eout2[i]<<" ";
    }
//----------------------------------------------------------------------
    cout<<"\n\n-----------------the result of round 2 expansion p box and k1 xor is :---------------------- \n";
    for (i=1;i<9;i++)
    {
        if(eout2[i] == k1[i])
        {
            Xor2[i]=0;
        }
        else
        {
            Xor2[i]=1;
        }
    }

    for (i=1;i<9;i++)
    {
        cout<<Xor2[i]<<" ";
    }

//-------------------------------------------------------------------------------------------------------------
    cout <<"\n\n-----------------s box 1 of round 2----------\n";
    cout<<"\nthe row is : ";
    r3=((2*Xor2[1])+Xor2[4]);
    cout << r3;

    cout<<"\nthe coloumn is : ";
    col3=((2*Xor2[2])+Xor2[3]);
    cout <<col3;

    cout<<"\nthe value on s box 1 is : ";
    s3out=s1[r3][col3];
    cout<<s3out<<endl;
    B2[0]=0;
    B2[1]=s3out / 2;
    B2[2]=s3out % 2;

    cout <<"\n---------------the s1 box output in binary :------------- : \n";
    for (i=1;i<3;i++)
    {
        cout<<B2[i]<<" ";
    }

//---------------------------------------------------------------------------------------------

    cout <<"\n-----------------round 2 s box 2----------\n";
    cout<<"\nthe row is : ";
    r4=((2*Xor2[5])+Xor2[8]);
    cout << r4;

    cout<<"\nthe coloumn is : ";
    col4=((2*Xor2[6])+Xor2[7]);
    cout <<col4;

    cout<<"\nthe value on s box 1 is : ";
    s4out=s2[r4][col4];
    cout<<s4out<<endl;

    B2[3]=s4out / 2;
    B2[4]=s4out % 2;

    cout <<"\n the s2 box output in binary : ";
    for (i=3;i<5;i++)
    {
        cout<<B2[i]<<" ";
    }
    //----------------------------------------------------------------------
    cout <<"\n-----------------result of round 2 s boxes----------\n";
    cout<<"\ncombining s1 box and s2 box output :\n";
    for (i=1;i<5;i++)
    {
        cout<<B2[i]<<" ";
    }
    cout<<endl;
    for (i=1;i<5;i++)
    {
        S2[i]=B2[i];
    }
//----------------------------------------------------------------------------
    cout <<"\n-----------------result of round 2 straight p box----------\n";

    for (i=1;i<5;i++)
    {
        spbo2[i]=S2[spb[i]];
    }

    for (i=1;i<5;i++)
    {
        cout<<spbo2[i]<<" ";
    }
//------------------------------------------------------------------
    cout <<"\n-----------------result straight p box of round 2 output XOR with left 4 bits of round 1 output----------\n";
    for (i=1;i<5;i++)
    {
        if (C2[i]==spbo2[i])
        {
            xsbpip2[i]=0;
        }
        else
        {
            xsbpip2[i]=1;
        }
    }

    for (i=1;i<5;i++)
    {
        cout<<xsbpip2[i]<<" ";
    }

//-------------------------------------------------------------------------------------------------
    cout <<"\n-----------------combining the xor result and P2 right 4 bits : ----------\n";
    for (i=1;i<5;i++)
    {
        P2[i]=xsbpip2[i];
    }
    for (i=5;i<9;i++)
    {
        P2[i]=C2[i];
    }
    for (i=1;i<9;i++)
    {
        cout<<P2[i]<<" ";
    }
//------------------------------------------------------------------------------------
    cout<<"\n------------------after final permutation :---------------- \n";
    cout<<"\n------------------the plaintext for given ciphertext is :---------------- \n";
    for (i=1;i<9;i++)
    {
        fpout[i]=P2[fp[i]];
    }

    for(i=1;i<9;i++)
    {
        cout<<fpout[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    sdes_encryption();
    cout<<"\n\n\n\n----------------------------------------------------------------------------------------------------------------\n\n";
    sdes_decryption();
    system("pause");
    return 0;

}
