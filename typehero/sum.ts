type Stringify<S extends string | number | bigint> =
  `${S}` extends `${infer Ans extends string}` ? Ans : never;
type CreateStrArr<S extends string> = S extends `${infer First}${infer Rest}`
  ? [0, ...CreateStrArr<Rest>]
  : [];
type LengthOfString<S extends string> = CreateStrArr<S>["length"];
type PadLeft<L extends number, B extends string> = LengthOfString<B> extends L
  ? B
  : PadLeft<L, `0${B}`>;

type Digit = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";

type AddDigit0 = {
  [S in Digit as `0${S}`]: S;
};
type AddDigitRest = {
  "11": "2";
  "12": "3";
  "13": "4";
  "14": "5";
  "15": "6";
  "16": "7";
  "17": "8";
  "18": "9";
  "19": "10";
  "22": "4";
  "23": "5";
  "24": "6";
  "25": "7";
  "26": "8";
  "27": "9";
  "28": "10";
  "29": "11";
  "33": "6";
  "34": "7";
  "35": "8";
  "36": "9";
  "37": "10";
  "38": "11";
  "39": "12";
  "44": "8";
  "45": "9";
  "46": "10";
  "47": "11";
  "48": "12";
  "49": "13";
  "55": "10";
  "56": "11";
  "57": "12";
  "58": "13";
  "59": "14";
  "66": "12";
  "67": "13";
  "68": "14";
  "69": "15";
  "77": "14";
  "78": "15";
  "79": "16";
  "88": "16";
  "89": "17";
  "99": "18";
};
type AddDigitOriginal = {
  [S in keyof AddDigit0 | keyof AddDigitRest]: S extends keyof AddDigit0
    ? AddDigit0[S]
    : S extends keyof AddDigitRest
    ? AddDigitRest[S]
    : never;
};
type Reverse<S extends string> = S extends `${infer First}${infer Rest}`
  ? `${Reverse<Rest>}${First}`
  : "";
type AddDigit = {
  [S in
    | keyof AddDigitOriginal
    | Reverse<
        string & keyof AddDigitOriginal
      >]: S extends keyof AddDigitOriginal
    ? AddDigitOriginal[S]
    : Reverse<S> extends keyof AddDigitOriginal
    ? AddDigitOriginal[Reverse<S>]
    : never;
};

type LargeTest<Num extends string> = Reverse<Num> extends `${infer Rest extends Digit}${infer First}` ? First extends "" ? [] : [First, Rest] : never;

type SumInternal<
  A extends string,
  B extends string,
  Carry extends boolean = false
> = LengthOfString<A> extends LengthOfString<B>
  ? LargeTest<A> extends [infer First extends string, infer Rest extends Digit]
    ? LargeTest<B> extends [infer First2 extends string, infer Rest2 extends Digit]
      ? // is 2 digit
        AddDigit[`${Rest}${Rest2}`] extends `${infer _A extends Digit}${infer _B extends Digit}`
        // ? unknown
        ? SumInternal<
            Reverse<First>,
            Reverse<First2>,
            true
          > extends `${infer RestSum extends string}`
          ? Carry extends true
            ? `${RestSum}${AddDigit[`${_B}1` extends keyof AddDigit
                ? `${_B}1`
                : never]}`
            : `${RestSum}${_B}`
          : never
        : Carry extends true
        // ? unknown
        ? AddDigit[`${Rest}${Rest2}`] extends "9"
          ? SumInternal<
              Reverse<First>,
              Reverse<First2>,
              true
            > extends `${infer RestSum extends string}`
            ? `${RestSum}0`
            : never
          : SumInternal<
              Reverse<First>,
              Reverse<First2>,
              false
            > extends `${infer RestSum extends string}`
          ? `${RestSum}${AddDigit[`${AddDigit[`${Rest}${Rest2}`]}1` extends keyof AddDigit
              ? `${AddDigit[`${Rest}${Rest2}`]}1`
              : never]}`
          : never
        : SumInternal<
            Reverse<First>,
            Reverse<First2>,
            false
          > extends `${infer RestSum extends string}`
        ? `${RestSum}${AddDigit[`${Rest}${Rest2}`]}`
        : never
      : never
    : Carry extends true
      ? AddDigit[`${A}${B}` extends keyof AddDigit ? `${A}${B}` : never] extends '9'
        ? '10'
        : never
      : AddDigit[`${A}${B}` extends keyof AddDigit ? `${A}${B}` : never]
  : CreateStrArr<A> extends [
      ...infer _,
      ...CreateStrArr<B>
    ]
  ? SumInternal<A, PadLeft<LengthOfString<A>, B>>
  : SumInternal<PadLeft<LengthOfString<B>, A>, B>;

type PadIt<A extends string, B extends string> = CreateStrArr<A> extends [
  ...infer _,
  ...CreateStrArr<B>
]
? PadLeft<LengthOfString<A>, B>
: PadLeft<LengthOfString<B>, A>;

type Sum<A extends string | bigint | number, B extends string | bigint | number> = SumInternal<
  Stringify<A>,
  Stringify<B>
>;
type CompQuick<A extends string> = LargeTest<A> extends [infer First extends string, infer Rest extends Digit] ? [First, Rest] : false;

type ExL = Sum<9999, 1>
