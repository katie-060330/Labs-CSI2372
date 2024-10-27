#include <cstdlib> 
class CardsSet {
public:
    CardsSet() : number(0) {}
    void novSet();
    void shuffle();
    int numCards() { return number; }
    Card take();
    void put(Card k);
    Card lookIn(int no);
    void empty() { number = 0; }

    Card set[52];
    private:
    int number;
};

void CardsSet::novSet(){
    
	
	 int t=0;
	 //for every color and face 
	  for(int i=club; i <= spade; i++){
       
        //?should deal with that as an edge case and add 13 from the value if it is over and if there is one ace 
	  	for(int j=1;j<= 13; j++){
			set[t] = Card(static_cast<color>(i), j);
	 		t++;

	  	}
	 }
}

void CardsSet::shuffle(){
    Card shuffled[52]; 
    int min  = 0; 
    int max = 51; 
    int arr[52];
    for(int i = 0; i < 52; i++){
        int randomInRange = min + rand() % (max - min + 1);
        //!generate a number that hasnt been gnerated before, usiong an array of the same size 
        while(arr[randomInRange] == 1){
             randomInRange = min + rand() % (max - min + 1);
        }
        shuffled[i] = set[randomInRange]; 
        arr[randomInRange] = 1; 
       
        

    }
    for(int i = 0; i < 52; i++){
        set[i] = shuffled[i];
    }


}