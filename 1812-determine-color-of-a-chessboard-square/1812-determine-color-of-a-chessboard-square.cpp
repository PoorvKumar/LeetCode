class Solution {
public:
    bool squareIsWhite(string coordinates) 
    {
//         int xCoordinate=coordinates[0]-'a'+1;
        
//         int yCoordinate=coordinates[1]-'0';
        
//         return (xCoordinate+yCoordinate)%2!=0;
        
        return (coordinates[0]-'a'+1+coordinates[1]-'0')%2!=0;
    }
};