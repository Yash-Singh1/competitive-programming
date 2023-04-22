  for (let i = 5; i < 10000; ++i) {
    for (let j = 5; j < 10000; ++j) {
      if ((4 * j + 5) * (4 * i + 5) - (3 * j + 2) * (3 * i + 2) == 2023) {
        console.log(i + j)
        process.exit(1)
      }
    }
  }
