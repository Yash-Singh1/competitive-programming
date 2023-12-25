// Purges all benchmark caches and results.

import { unlinkSync } from "node:fs";

function purge() {
  unlinkSync("bench.json");
}

purge();
