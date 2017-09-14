#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;
struct role
{
    int ccount;
    string cat[10];
};
struct user
{
    int rcount;
    string role[10];
};
map<string,int> cats;
map<string,role> roles;
map<string,user> users;
map<string,int> temp;
struct role role;
struct user user;
int main()
{
	freopen("input.txt","r",stdin);
    int p,r,u,q;
    int i,j,k;
    int length;
    string power;
    cin>>p;
    for(i=0;i<p;i++)
    {
        cin>>power;
        length=power.length();
        k=power[length-1]-'0';
        if(k>=0&&k<=9)
        {
            cats[power.substr(0,length-2)]=k;
        }
        else
        {
            cats[power]=-1;
        }
    }
    cin>>r;
    string rolename;
    for(i=0;i<r;i++)
    {
        for(j=0;j<10;j++)
        {
            role.cat[j]="";
        }
        cin>>rolename;
        cin>>role.ccount;
        for(j=0;j<role.ccount;j++)
        {
            cin>>role.cat[j];
        }
        roles[rolename]=role;
    }
    string username;
    cin>>u;
    for(i=0;i<u;i++)
    {
        for(j=0;j<10;j++)
        {
            user.role[j]="";
        }
        cin>>username;
        cin>>user.rcount;
        for(j=0;j<user.rcount;j++)
        {
            cin>>user.role[j];
        }
        users[username]=user;
    }
    cin>>q;
    string query;
    int level;
    for(i=0;i<q;i++)
    {
        cin>>username;
        cin>>query;
        temp.clear();
        if(users.find(username)==users.end())
        {
            cout<<"false"<<endl;
            continue;
        }
        else
        {
            user=users[username];
            for(j=0;j<user.rcount;j++)
            {
                rolename=user.role[j];
                role=roles[rolename];
                for(k=0;k<role.ccount;k++)
                {
                    string catname=role.cat[k];
                    length=catname.length();
                    if(catname[length-2]==':')
                    {
                        level=catname[length-1]-'0';
                        catname=catname.substr(0,length-2);
                        if(temp.find(catname)==temp.end())
                        {
                            temp[catname]=level;
                        }
                        else
                        {
                            if(temp[catname]<level)
                            {
                                temp[catname]=level;
                            }
                        }
                    }
                    else
                    {
                        temp[catname]=-1;
                    }
 
                }
            }
 
        }
        level=-1;
        length=query.length();
        if(query[length-2]==':')
        {
            level=query[length-1]-'0';
            query=query.substr(0,length-2);
        }
        if(temp.find(query)==temp.end())
        {
            cout<<"false"<<endl;
            continue;
        }
        if(level==-1)
        {
            if(temp[query]==-1)
            {
                cout<<"true"<<endl;
            }
            else
            {
                cout<<temp[query]<<endl;
            }
        }
        else
        {
            if(temp[query]>=level)
            {
                cout<<"true"<<endl;
            }
            else
            {
                cout<<"false"<<endl;
            }
        }
 
    }
}
