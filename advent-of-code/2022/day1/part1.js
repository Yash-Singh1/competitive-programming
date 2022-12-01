input.split('\n\n').map(i => i.split('\n').map(s => parseInt(s, 10)).reduce((acc, n) => acc + n, 0)).reduce((acc, name) => Math.max(acc, name), 0)
