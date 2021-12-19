firstLine = [*map(int, input().split(' '))]
n = firstLine[0]
t = firstLine[1]

infected = [*map(lambda infectdOrNot: True if infectdOrNot == '1' else False, input())]

interactions = []
for i in range(t):
  interaction = [*map(int, input().split(' '))]
  if not(infected[interaction[1] - 1] == False and infected[interaction[2] - 1] == False):
    interactions.append(interaction)

interactions.sort(key=lambda interaction: interaction[0])

possiblePatientZeroes = []
for cow in range(n):
  pairs = [*filter(lambda interaction: cow + 1 in interaction[1:], interactions)]
  if infected[cow] == True and (
    len(pairs) == 0 or
    (
      (pairs[0][2] - 1 != cow and infected[pairs[0][2] - 1] == True) or
      (pairs[0][1] - 1 != cow and infected[pairs[0][1] - 1] == True)
    )
  ):
    possiblePatientZeroes.append(cow)

def works(patientZero, k):
  simulated_infected = []
  simulated_handshakes = []
  for _ in range(n):
    simulated_infected.append(False)
    simulated_handshakes.append(0)
  simulated_infected[patientZero] = True
  for time in range(250):
    interaction = None
    for iteratingInteraction in interactions:
      if iteratingInteraction[0] == time + 1:
        interaction = iteratingInteraction
    if interaction == None:
      continue
    if simulated_infected[interaction[1] - 1]:
      simulated_handshakes[interaction[1] - 1] += 1
    if simulated_infected[interaction[2] - 1]:
      simulated_handshakes[interaction[2] - 1] += 1
    if simulated_handshakes[interaction[1] - 1] <= k and simulated_infected[interaction[1] - 1]:
      simulated_infected[interaction[2] - 1] = True
    if simulated_handshakes[interaction[2] - 1] <= k and simulated_infected[interaction[2] - 1]:
      simulated_infected[interaction[1] - 1] = True
  for cow in range(n):
    if infected[cow] != simulated_infected[cow]:
      return False
  return True

patientZeroes = []
ks = []

for possible_k in range(1, t + 2):
  for cow in possiblePatientZeroes:
    if works(cow, possible_k):
      patientZeroes.append(cow)
      ks.append(possible_k)

maximum = max(ks)

print(len(set(patientZeroes)), min(ks), 'Infinity' if maximum == t + 1 else maximum)
