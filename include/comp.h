#ifndef COMP_H
#define COMP_H


class comp
{
     bool reverse;
public:
  comp(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const pair<double,int>& p1, const pair<double,int>&p2) const
  {
    if (reverse) return (p1.first>p2.first);
    else return (p1.first<p2.first);
  }
  protected:
  private:
};

#endif // COMP_H
