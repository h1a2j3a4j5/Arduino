

bool isCuntr = true , c = true;


void setup () {
  setupStoper();
  isCuntr = true;
}



void loop() {
 if(isbtnPress ()){
   isCuntr = true;
}
 
if(c){
  Time (159);
  c = false;
}
   
 if(isCuntr){
  setoperLoop ();
  Counter() ;
}

 if(isTimeFinish()){
  isCuntr = false;
}
 

}
