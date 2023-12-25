interface Benchmap {
  skip: string[];
  map: {
    [dayNum: number]: {
      silver?: string;
      gold?: string;
    };
  };
  runtimeMap: {
    [dayNum: number]: {
      silver?: "node";
      gold?: "node";
    };
  };
}

const benchmap = {
  skip: ["day22/silver"],
  map: {
    20: {
      gold: "gold2.ts",
    },
    21: {
      silver: "gold2.ts",
      gold: "goldviz.ts",
    },
    23: {
      gold: "goldb.ts",
    },
    24: {
      gold: "gold.cjs",
    },
    25: {
      silver: "silver2.ts",
    },
  },
  runtimeMap: {
    24: {
      gold: "node",
    },
  },
} as Benchmap;

export default benchmap;
