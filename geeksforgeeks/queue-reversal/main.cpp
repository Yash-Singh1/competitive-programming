//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
      stack<int> rq;
  while (!q.empty())
  {
    rq.push(q.front());
    q.pop();
  }
  while (!rq.empty()) {
      q.push(rq.top());
      rq.pop();
  }
  return q;
}
