/*
 * 332. Reconstruct itinerary
 *
 * Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the 
 * itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
 *
 * Note:
 *   - If there are multiple valid itineraries, you should return the itinerary that has the smallest 
 *     lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
 *   - All airports are represented by three capital letters (IATA code).
 *   - You may assume all tickets form at least one valid itinerary.
 **/

#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

bool itinerary(const string& ap, vector<string>& it, unordered_map<string, multiset<string> >& ap_to_dsts, int fl) {
  if (fl == 0) return true;
  multiset<string>& dsts = ap_to_dsts[ap];
  multiset<string>::iterator dst_it = dsts.begin();
  while (dst_it != dsts.end()) {
    string next_ap = *dst_it;
    dsts.erase(dst_it);
    it[it.size()-fl] = next_ap;
    if (itinerary(next_ap, it, ap_to_dsts, fl-1)) return true;
    dst_it = dsts.insert(next_ap);
    while (dst_it != dsts.end() && *dst_it == next_ap) ++dst_it;
  }

  return false;
}

vector<string> findItinerary(vector<pair<string, string> > tickets) {
  unordered_map<string, multiset<string> > ap_to_dsts;
  for (auto ticket : tickets) 
    ap_to_dsts[ticket.first].insert(ticket.second);

  vector<string> it(tickets.size()+1);
  string starting_ap = "JFK";
  it[0] = starting_ap;
  itinerary(starting_ap, it, ap_to_dsts, tickets.size());

  return it;
}
