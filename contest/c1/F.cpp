#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#define rank rankdds__
#define MAXN 1000010

using namespace std;

int n , m , stack_top , cnt , a[ MAXN ] , b[ MAXN ];

#define Node RedBlackTree_Node

struct Node
{
	int data , size , c;
	bool color;
	Node * fa , * ch[2];
	void set( const int & _v , const bool & _color , const int & i , register Node * p )
	{
		data = _v , color = _color , size = c = i;
		fa = ch[0] = ch[1] = p;
	}
	void push_up()
	{
		size = ch[0] -> size + ch[1] -> size + c;
	}
	void push_down()
	{
		for( Node * x = this ; x -> size ; x = x -> fa ) x -> size--;
	}
	int cmp( const int & v ) const
	{
		return data == v ? -1 : v > data;
	}
} stack[ MAXN << 1 ] , * tail , * store[ MAXN << 1 ] , * rbt_null;

inline void init_RedBlackTree()
{
	tail = & stack[0];
	rbt_null = tail++;
	rbt_null -> set( 0 , 0 , 0 , 0 );
	stack_top = 0;
}

struct RedBlackTree
{
	Node * rbt_root;
	void init()
	{
		rbt_root = rbt_null;
	}
	Node * new_Node( const int & v )
	{
		register Node * p = rbt_null;
		if( !stack_top ) p = tail++;
		else p = store[ --stack_top ];
		p -> set( v , 1 , 1 , rbt_null );
		return p;
	}
	void rotate( register Node * & x , const bool & d )
	{
		register Node * y = x -> ch[ !d ];
		x -> ch[ !d ] = y -> ch[d];
		if( y -> ch[ d ] -> size ) y -> ch[ d ] -> fa = x;
		y -> fa = x -> fa;
		if( ! x -> fa -> size ) rbt_root = y;
		else x -> fa -> ch[ x -> fa -> ch[ 0 ] != x ] = y;
		y -> ch[ d ] = x;
		x -> fa = y;
		y -> size = x -> size;
		x -> push_up();
	}
	void insert( const int & v )
	{
		register Node * x = rbt_root , * y = rbt_null;
		while( x -> size )
		{
			x -> size++ , y = x;	
			int d = x -> cmp( v );
			if( d == -1 )
			{
				x -> c++;
				return;
			}
			x = x -> ch[ d ];
		}
		x = new_Node( v );
		if( y -> size ) y -> ch[ v > y -> data ] = x;
		else rbt_root = x;
		x -> fa = y;
		insert_fix( x );
	}
	void insert_fix( register Node * & x)
	{
		while( x -> fa -> color )
		{
			Node * parent = x -> fa , * grandparent = parent -> fa;
			bool d = parent == grandparent -> ch[ 0 ];
			Node * uncle = grandparent -> ch[ d ];
			if( uncle -> color )
			{
				parent -> color = uncle -> color = 0;
				grandparent -> color = 1;
				x = grandparent;
			}
			else if( x == parent -> ch[ d ] )
				rotate( x = parent , !d );
			else
			{
				grandparent -> color = 1;
				parent -> color = 0;
				rotate( grandparent , d );
			}
		}
		rbt_root -> color = 0;
	}
	Node * find( register Node * x , int data )
	{
		while( x -> size && x -> data != data )
			x = x -> ch[ x -> data < data ];
		return x;
	}
	void del_fix( register Node * & x)
	{
		while( x != rbt_root && !x -> color )
		{
			register bool d = x == x -> fa -> ch[ 0 ];
			Node * parent = x -> fa , * sibling = parent -> ch[ d ];
			if( sibling -> color )
			{
				sibling -> color = 0;
				parent -> color = 1;
				rotate( x -> fa , !d );
				sibling = parent -> ch[ d ];
			}
			else if( !sibling -> ch[ 0 ] -> color && !sibling -> ch[ 1 ] -> color )
				sibling -> color = 1 , x = parent;
			else
			{
				if( !sibling -> ch[ d ] -> color )
				{
					sibling -> ch[ !d ] -> color = 0;
					sibling -> color = 1;
					rotate( sibling , d );
					sibling = parent -> ch[ d ];
				}
				sibling -> color = parent -> color;
				sibling -> ch[ d ] -> color = parent -> color = 0;
				rotate( parent , !d );
				break;
			}
		}
		x -> color = 0;
	}
	void erase( const int & data )
	{
		register Node * z = find( rbt_root , data );
		if( !z -> size ) return;
		if( z -> c > 1 )
		{		
			z -> c--;
			z -> push_down();
			return;
		}
		register Node * y = z , * x = rbt_null;
		if( z -> ch[ 0 ] -> size && z -> ch[ 1 ] -> size )
		{
			y = z -> ch[ 1 ];
			while( y -> ch[ 0 ] -> size )
				y = y -> ch[ 0 ];
		}
		x = y -> ch[ !y -> ch[ 0 ] -> size ];
		x -> fa = y -> fa;
		if( !y -> fa -> size ) rbt_root = x;
		else y -> fa -> ch[ y -> fa -> ch[ 1 ] == y ] = x;
		if( z != y ) z -> data = y -> data , z -> c = y -> c;
		y -> fa -> push_down();
		for( Node * k = y -> fa ; y -> c > 1 && k -> size && k != z ; k = k -> fa ) k -> size -= y -> c - 1;
		if( !y -> color ) del_fix( x );
		store[ stack_top++ ] = y;
	}
	int find( register int k )
	{
		register int t;
		register Node * x = rbt_root;
		while( x -> size )
		{
			t = x -> ch[ 0 ] -> size;
			if( k <= t ) x = x -> ch[ 0 ];
			else if( t + 1 <= k && k <= t + x -> c ) break;
			else k -= t + x -> c , x = x -> ch[ 1 ];
		}
		return x -> data;
	}
} rbt_root[ MAXN ];

#undef Node

int size[ MAXN ] , fa[ MAXN ] , son[ MAXN ] , top[ MAXN ] , dep[ MAXN ] , l[ MAXN ];
vector < int > linker[ MAXN ];

#define cur linker[x][i]

void dfs1( int x )
{
	size[x] = 1;
	for( int i = 0 ; i < linker[x].size() ; i++ )
		if( cur != fa[x] )
		{
			dep[ cur ] = dep[x] + 1 , fa[ cur ] = x;
			dfs1( cur ) , size[x] += size[ cur ];
			if( size[ cur ] > size[ son[x] ] ) son[x] = cur;
		}
}

int tot;

void dfs2( int x , int t )
{
	l[x] = ++tot , b[ tot ] = a[x] , top[x] = t;
	if( son[x] ) dfs2( son[x] , t );
	for( int i = 0 ; i < linker[x].size() ; i++ )
		if( cur != fa[x] && cur != son[x] )
			dfs2( cur , cur );
}

int rank[ MAXN ] , use[ MAXN ];
vector < int > change[ MAXN ] , value[ MAXN ];

#undef cur
#define new_Node( size , v , a , b ) ( & ( * st[ cnt++ ] = Node( size , v , a , b ) ) )
#define up( x ) x += cur -> tag
#define merge( a , b ) new_Node( a -> size + b -> size , 0 , a , b )
#define update( cur ) if( cur -> left -> size ) cur -> size = cur -> left -> size + cur -> right -> size
#define Node FingerTree_Node

struct Node
{
	int size , value , tag , rev;
	Node * left , * right;
	Node( const int & size , const int & v , register Node * a , register Node * b ) : size( size ) , value( v ) , left( a ) , right( b ) , tag( 0 ) , rev( 0 ) {}
	Node() {}
} * fgt_root , * fgt_null , t[ MAXN << 2 ] , * st[ MAXN << 2 ];

inline void pushdown( register Node * cur )
{
	if( cur -> left -> size )
	{
		if( cur -> tag )
		{
			up( cur -> left -> tag );
			up( cur -> right -> tag );
			cur -> tag = 0;
		}
		if( cur -> rev )
		{
			cur -> left -> rev ^= 1 , cur -> right -> rev ^= 1;
			swap( cur -> left , cur -> right );
			cur -> rev = 0;
		}
	}
	else
	{
		if( cur -> tag ) up( cur -> value ) , cur -> tag = 0;
		cur -> rev = 0;
	}
}

Node * build( int l , int r )
{
	if( l == r ) return new_Node( 1 , b[l] , fgt_null , fgt_null );
	Node * left = build( l , l + r >> 1 ) , * right = build( ( l + r >> 1 ) + 1 , r );
	return merge( left , right );
}

void modify( int l , int r , int t , Node * cur )
{
	pushdown( cur );
	if( cur -> size == r - l + 1 ) cur -> tag += t , pushdown( cur );
	else if( l > cur -> left -> size ) modify( l - cur -> left -> size , r - cur -> left -> size , t , cur -> right );
	else if( cur -> left -> size >= r ) modify( l , r , t , cur -> left );
	else modify( l , cur -> left -> size , t , cur -> left ) , modify( 1 , r - cur -> left -> size , t , cur -> right );
}

inline void modify( int a , int b , int c )
{
	while( top[a] != top[b] )
	{
		if( dep[ top[a] ] < dep[ top[b] ] ) swap( a , b );
		modify( l[ top[a] ] + 1 , l[a] + 1 , c , fgt_root );
		a = fa[ top[a] ];
	}
	if( dep[a] > dep[b] ) swap( a , b );
	return modify( l[a] + 1 , l[b] + 1 , c , fgt_root );
}

inline void operate( int a , int b )
{
	while( top[a] != top[b] )
	{
		if( dep[ top[a] ] < dep[ top[b] ] ) swap( a , b );
		change[ fa[ top[a] ] ].push_back( top[a] );
		a = fa[ top[a] ];
	}
	if( dep[a] > dep[b] ) swap( a , b );
	if( a == top[a] ) change[ fa[ top[a] ] ].push_back( top[a] );
}

#define find_value( x ) find( x + 1 , fgt_root )

int find( int x , Node * cur )
{
	pushdown( cur );
	if( cur -> size == 1 ) return cur -> value;
	return x > cur -> left -> size ? find( x - cur -> left -> size , cur -> right ) : find( x , cur -> left );
}

void split( int x , Node * cur )
{
	pushdown( cur );
	if( x > cur -> left -> size ) split( x - cur -> left -> size , cur -> right ) , cur -> left = merge( cur -> left , cur -> right -> left ) , st[ --cnt ] = cur -> right , cur -> right = cur -> right -> right;
	else if( x < cur -> left -> size ) split( x , cur -> left ) , cur -> right = merge( cur -> left -> right , cur -> right ) , st[ --cnt ] = cur -> left , cur -> left = cur -> left -> left;
}

inline void get_interval( int l , int r )
{
	split( r + 1 , fgt_root ) , split( l , fgt_root -> left );
}

#define cur fgt_root -> left -> right

struct point
{
	int x , y , X;
	point( int x , int y ) : x( x ) , y( y ) , X( x ) {}
};

#define len( a ) v[a].y - v[a].x + 1

inline void invert( int a , int b )
{
	vector < point > v1 , v2 , v;
	while( top[a] != top[b] )
		if( dep[ top[a] ] < dep[ top[b] ] ) v2.push_back( point( l[ top[b] ] , l[b] ) ) , b = fa[ top[b] ];
		else v1.push_back( point( l[ top[a] ] , l[a] ) ) , a = fa[ top[a] ];
	if( dep[a] > dep[b] ) v1.push_back( point( l[b] , l[a] ) );
	else v2.push_back( point( l[a] , l[b] ) );
	reverse( v2.begin() , v2.end() );
	for( register int i = 0 ; i < v1.size() ; i++ ) v.push_back( v1[i] );
	for( register int i = 0 ; i < v2.size() ; i++ ) v.push_back( v2[i] );
	Node * now = new_Node( 1 , -1 , fgt_null , fgt_null ) , * temp;
	for( register int i = 0 ; i < v.size() ; i++ )
	{
		get_interval( v[i].x , v[i].y );
		for( register int j = 0 ; j < v.size() ; j++ )
			if( v[i].X < v[j].X )
				v[j].x -= len( i ) , v[j].y -= len( i );
		if( i < v1.size() ) cur -> rev ^= 1;
		now = merge( now , cur );
		st[ --cnt ] = fgt_root -> left , fgt_root -> left = fgt_root -> left -> left;
		update( fgt_root -> left );
		update( fgt_root );
	}
	now -> rev ^= 1;
	for( register int i = 0 ; i < v.size() ; i++ )
	{
		split( v[i].x , fgt_root );
		split( len( i ) , now );
		if( i < v1.size() ) now -> left -> rev ^= 1;
		fgt_root -> left = merge( fgt_root -> left , now -> left );
		update( fgt_root ) , st[ --cnt ] = now , now = now -> right;
		for( register int j = 0 ; j < v.size() ; j++ )
			if( v[i].X < v[j].X )
				v[j].x += len( i ) , v[j].y += len( i );
	}
	st[ --cnt ] = now;
}

#undef cur

#define cur change[x][i]

inline void find_begin( int x )
{
	if( son[x] ) rbt_root[x].insert( find_value( l[ son[x] ] ) );
	if( fa[x] ) rbt_root[x].insert( find_value( l[ fa[x] ] ) );
	rbt_root[x].insert( find_value( l[x] ) );
	for( register int i = 0 ; i < change[x].size() ; i++ )
		if( !use[ cur ] )
		{
			use[ cur ] = 1;
			rbt_root[x].erase( value[x][ rank[ cur ] ] );
			value[x][ rank[ change[x][i] ] ] = find_value( l[ cur ] );
			rbt_root[x].insert( value[x][ rank[ cur ] ] );
		}
	for( register int i = 0 ; i < change[x].size() ; i++ )
		use[ change[x][i] ] = 0;
	change[x].clear();
}

#undef cur

inline void find_end( int x )
{
	if( son[x] ) rbt_root[x].erase( find_value( l[ son[x] ] ) );
	if( fa[x] ) rbt_root[x].erase( find_value( l[ fa[x] ] ) );
	rbt_root[x].erase( find_value( l[x] ) );
}

inline void addedge( int x , int y )
{
	linker[x].push_back( y );
	linker[y].push_back( x );
}

#undef cur

#define cur linker[x][i]

inline void init()
{
	init_RedBlackTree();
	for( register int i = 0 ; i < MAXN << 2 ; i++ ) st[i] = & t[i];
	dfs1( 1 ) , dfs2( 1 , 1 );
	fgt_null = new_Node( 0 , 0 , 0 , 0 );
	fgt_root = build( 0 , n + 1 );
	for( int x = 1 ; x <= n ; x++ )
	{
		rbt_root[x].init();
		for( register int i = 0 ; i < linker[x].size() ; i++ )
		{
			value[x].push_back( a[ cur ] );
			if( cur != son[x] && cur != fa[x] )
			{
				rbt_root[x].insert( a[ cur ] );
				rank[ cur ] = i;
			}
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for( register int i = 1 ; i <= n ; i++ ) {
		scanf("%d", &a[i]);
	}
	for( register int i = 1 ; i < n ; i++ ) {
		int x, y; scanf("%d %d", &x, &y);
		addedge(x, y);
	} 
	init();
	int totLine = 0;
	while( m-- )
	{
		int opt, x, y; scanf("%d %d %d", &opt, &x, &y);
		if( opt == 1 ) invert( x , y ) , operate( x , y );
		else if( opt == 2 ) {
			int k; scanf("%d", &k);
			modify( x , y , k ) , operate( x , y );
		}
		else
		{
			find_begin( x );
			while( y-- ) {
				int k; scanf("%d", &k);
				totLine++;
				printf("%d\n", rbt_root[x].find( k ) );
			}
			find_end( x );
		}
	}
	return 0;
}