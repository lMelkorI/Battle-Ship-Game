#include <iostream>
  int firstBoard[9][9]={
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
  };
  int secondBoard[9][9]={
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
  };;
  std::string P1;
  std::string P2;
  int ship=4;
  std::string cordinates;
  int x,y;
  std::string bye;
  int shipP1,shipP2;
  std::string hitCordinatesP1[],hitCordinatesP2[];
  std::string cordinate;
void get(int player){
  using namespace std;
  cout<<"Insert the cordinates you want to place your ships (1,9)\n";
  if(player==1){
    cout<<P1<<": Fill your board!\n";
    for(int i=0;i<ship;i++){
    cin>>cordinates;
    x=cordinates[1]-'0';
    y=cordinates[3]-'0';
    firstBoard[x-1][y-1]=1;
    }
  }
  else{
    cout<<P2<<": Fill your board!\n";
    for(int i=0;i<ship;i++){
    cin>>cordinates;
    x=cordinates[1]-'0';
    y=cordinates[3]-'0';
    secondBoard[x-1][y-1]=1;
    }
  }
  std::system("CLS");
  }

void hit(){
  using namespace std;
  int turn=0;
  shipP1=ship;
  shipP2=ship;
  while (shipP1>0 && shipP2>0){
    if (turn%2==0){
    cout<<P1<<"'s board\n";
    for (int i=0;i<9;i++){
      for (int j=0;j<9;j++){
        cout<<firstBoard[i][j]<<" ";
      }
    cout<<"\n";
    }
      cout<<P1<<":Chose your atack point!\n";
      cin>>cordinates;
      x=cordinates[1]-'0';
      y=cordinates[3]-'0';
      if (secondBoard[x-1][y-1]==1){
        cout<<"HIT!!\n";
        secondBoard[x-1][y-1]=2;
        shipP2--;
        std::system("pause");
      }
      else{
        cout<<"You missed\n";
        std::system("pause");
      }
      std::system("CLS");
      std::system("pause");
      }
    else{
      cout<<P2<<"'s board\n";
      for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
          cout<<secondBoard[i][j]<<" ";
        }
      cout<<"\n";
      }
      cout<<P2<<":Choose your atack point!\n";
      cin>>cordinates;
      x=cordinates[1]-'0';
      y=cordinates[3]-'0';
      if (firstBoard[x-1][y-1]==1){
        cout<<"HIT!!\n";
        firstBoard[x-1][y-1]=2;
        shipP1--;
        std::system("pause");
      }
      else{
        cout<<"You missed\n";
        std::system("pause");
      }
      std::system("CLS");
      std::system("pause");
    }
    turn++;
  }
}
void checkWin(){
  using namespace std;
  cout<<"Game is over!\n";
  if (shipP2==0){
    cout<<P1;
  }
  else{
    cout<<P2;
  }
  cout<<" has won the game.\n";
}
int main(){
  using namespace std;

  cout<<"P1: Your name:";
  cin>>P1;
  cout<<"P2: Your name:";
  cin>>P2;
  std::system("CLS");

  get(1);
  get(2);
  std::system("pause");
  std::system("CLS");
  hit();
  std::system("CLS");
  checkWin();

  system("pause");
  return 0;
}