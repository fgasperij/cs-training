#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> ipadresses() {
  vector<string> res;
  string A;
  cin >> A;

  if (A.size() > 12 || A.size() < 4) return res;

  string cl; string cml; string cmr; string cr;
  int l, ml, mr, r;
  string cres;
  for (int ii = 1; ii <= 3; ++ii) {
    cl += A[ii-1];
    l = stoi(cl, nullptr, 10);
    for (int ij = 1; ij <= 3; ++ij) {
      cml.clear();
      for (int a = ii; a < ii+ij; ++a) {
        cml += A[a];
      }
      ml = stoi(cml, nullptr, 10);
      for (int ik = 1; ik <= 3; ++ik) {
        cmr.clear();
        for (int b = ii+ij; b < ii+ij+ik; ++b) {
          cmr += A[b];
        }
        mr = stoi(cmr, nullptr, 10);
        int cr_size = A.size()-(ii+ij+ik);

        if (cr_size < 1 || cr_size > 3) continue;

        cr.clear();
        for (int c = ii+ij+ik; c < A.size(); ++c) {
          cr += A[c];
        }
        mr = stoi(cr, nullptr, 10);

        if ((l < 255 && (l != 0 || cl.size() == 1)) &&
            (ml < 255 && (ml != 0 || cml.size() == 1)) &&
            (mr < 255 && (mr != 0 || cmr.size() == 1)) &&
            (r < 255 && (r != 0 || cr.size() == 1))) {
          cres.clear();
          cres += cl; cres += ".";
          cres += cml; cres += ".";
          cres += cmr; cres += ".";
          cres += cr;
          res.push_back(cres);
        }
      }
    }
  }

  return res;
}
