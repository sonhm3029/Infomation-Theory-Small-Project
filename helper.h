#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;


template<typename arr_type>
void in_mang(vector <arr_type> arr) {
  for(int i = 0; i<arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

double luong_tin_rieng(double p_xi) {
  return -(log2(p_xi));
}

// Ham kiem tra gia tri dau vao co phai la expression khong
bool include_expression(string dau_vao) {
  for(int i = 0; i<dau_vao.size(); i++) {
    if(dau_vao[i] == '/') {
      return true;
    }
  }
  return false;
}

// Ham tinh toan gia tri dau vao neu no la mot bieu thuc
// Trong ham co su dung ham stod() la chuyen doi tu string sang double
double calc_expression(string dau_vao) {
  if(include_expression(dau_vao)) {
    int operator_index;
    string tu ="";
    string mau= "";

    for(int i = 0; i<dau_vao.size(); i++) {
      if(dau_vao[i] != '/') {
        tu += dau_vao[i];
      }
      else {
        operator_index = i;
        break;
      }
    }

    for(int i = operator_index+1; i<dau_vao.size();i++) {
      mau += dau_vao[i];
    }

    double result = stod(tu)/stod(mau);
    return result;

  }else {
    return stod(dau_vao);
  }
}

double binary_to_decimal(string binary) {
  double sum = 0;
  for(int i = 0; i<binary.size(); i++) {
    if(binary[i] == '1') {
      sum += pow(2,binary.size()-i-1);
    }
  }
  return sum;
}

void binary_sort(vector<string> &mang) {
    for(int i = 0; i<mang.size() - 1; i++) {
      for(int j = i+1; j<mang.size(); j++) {

        bool dk1 = (binary_to_decimal(mang[i]) >binary_to_decimal(mang[j])&&mang[i].size() == mang[j].size());
        bool dk2 = mang[i].size() > mang[j].size();

        if(dk1||dk2) {
          swap(mang[i], mang[j]);
        }
      }
    }
}

template<typename kieu_numeric>
void sort(vector<kieu_numeric> &mang) {
  for(int i =0; i<mang.size()-1; i++) {
    for(int j = i+1; j<mang.size(); j++) {
      if(mang[i] > mang[j]) {
        swap(mang[i],mang[j]);
      }
    }
  }
}

bool isPre(string ma1, string ma2) {
  if(ma1.size() < ma2.size()) {
    string prefix = "";
    for(int i =0; i<ma1.size(); i++) {
      prefix +=ma2[i];
    }
    if(ma1 == prefix) {
      return true;
    }
  }
  if(ma1.size() > ma2.size()) {
    string prefix = "";
    for(int i =0; i<ma2.size(); i++) {
      prefix +=ma1[i];
    }
    if(ma2 == prefix) {
      return true;
    }
  }
  return false;
}

string take_rest(string ma1, string ma2) {
  string rest="";

  if(isPre(ma1,ma2)) {
    if(ma1.size() > ma2.size()) {
      for(int i = ma2.size(); i<ma1.size(); i++) {
        rest +=ma1[i];
      }
    }
    else {
      for(int i = ma1.size(); i<ma2.size(); i++) {
        rest +=ma2[i];
      }
    }
  }

  return rest;
}

bool includes(vector<string> arr, string key) {
  for(int i = 0; i<arr.size(); i++) {
    if(key == arr[i]) {
      return true;
    }
  }
  return false;
}

template <typename kieu_dl>
bool isSame(vector <kieu_dl> arr1, vector<kieu_dl> arr2) {
  if(arr1.size() != arr2.size()) {
    return false;
  }
  for(int i = 0; i<arr1.size(); i++) {
    if(arr1[i] != arr2[i]) {
      return false;
    }
  }
  return true;
}