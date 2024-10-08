// RUN: %check_clang_tidy -std=c++17 %s modernize-avoid-c-arrays %t

int not_main(int argc, char *argv[]) {
  // CHECK-MESSAGES: :[[@LINE-1]]:24: warning: do not declare C-style arrays, use std::array<> or std::vector<> instead
  int f4[] = {1, 2};
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: do not declare C-style arrays, use std::array<> instead
}

int main(int argc, char *argv[]) {
  int f5[] = {1, 2};
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: do not declare C-style arrays, use std::array<> instead

  auto not_main = [](int argc, char *argv[]) {
    // CHECK-MESSAGES: :[[@LINE-1]]:32: warning: do not declare C-style arrays, use std::array<> or std::vector<> instead
    int f6[] = {1, 2};
    // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: do not declare C-style arrays, use std::array<> instead
  };
}
