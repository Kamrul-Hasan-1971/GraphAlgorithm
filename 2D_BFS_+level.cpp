#define          ll                     long long int
#define          pii                    pair < ll, ll>

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};

char ara[ N ][ N ] ;
ll visited[ N ][ N ] ;
ll level[ N ][ N ] ;
ll row, col ;

bool isvalid(ll x,ll y)
{
    if(x >= 0 && x < row && y >= 0 && y < col && ara[ x ][ y ] != '#' && visited[ x ][ y ] == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BFS( ll x, ll y )
{
    queue< pii > Q ;
    Q.push( pii( x, y ) ) ;
    visited[ x ][ y ] = 1 ;

    while( !Q.empty() )
    {
        ll m = Q.front().first;
        ll n = Q.front().second;
        Q.pop() ;

        for( ll i = 0 ; i < 4 ; i ++ )
        {
            ll xx = m + fx[ i ] ;
            ll yy = n + fy[ i ] ;

            if( isvalid( xx, yy ) )
            {
                level[ xx ][ yy ] = level[ m ][ n ] + 1 ;
                visited[ xx ][ yy ] = 1 ;
                Q.push( pii( xx, yy ) ) ;
            }
        }

    }
}

