int recentReadingsAdj[3] = {0,0,0}; //Left to right = recent to old
int recentReadingSummation = 0;

void chainBar(){
  int speed;
  int current = encoderGet(encoderChainB);
  if(current != recentReadingsAdj[0]){
    recentReadingsAdj[2] = recentReadingsAdj[1];
    recentReadingsAdj[1] = recentReadingsAdj[0];
    recentReadingsAdj[0] = current;
    recentReadingSummation = 0;
  }
  else {
    recentReadingSummation += current;
    if(recentReadingSummation / current == 4 && recentReadingSummation % current == 0){
      recentReadingsAdj = {current,current,current};
    }
  }
}