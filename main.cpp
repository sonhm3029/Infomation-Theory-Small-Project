#include <iostream>
#include <vector>
#include <string.h>
#include "helper.h"
#include "NguonTin.h"
#include "BoMa.h"

using namespace std;


int main() {

  BoMa example;
  example.khoi_tao();
  example.show_bo_ma();
  cout<<example.giai_ma();
  return 0;
} 