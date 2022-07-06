// Will give TLE just here for practice
queue<int> rev(queue<int> q)
{
    int f{q.front()};
    q.pop();
    if (q.empty()) {
        q.push(f);
        return q;
    } else {
        q = rev(q);
        q.push(f);
    }
  return q;
}
