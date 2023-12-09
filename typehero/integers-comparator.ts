enum Comparison {
  Greater,
  Equal,
  Lower,
}

type Digits = "0123456789"
type CompareDigit<S1 extends string, S2 extends string> =
  S1 extends S2 ? Comparison.Equal :
  Digits extends `${infer First}${S1}${infer _}`
    ? Digits extends `${infer First2}${S2}${infer _}`
      ? CreateStrArr<First> extends [...CreateStrArr<First2>, ...(infer _)]
        ? Comparison.Greater
        : Comparison.Lower
    : never
  : never;
type CreateStrArr<S extends string> = S extends `${infer First}${infer Rest}` ? [First, ...CreateStrArr<Rest>] : []
type LengthOfString<S extends string> = CreateStrArr<S>['length']
type _CompareStrings<A extends string, B extends string> = A extends B ? Comparison.Equal : CreateStrArr<A> extends [...CreateStrArr<B>, ...(infer _)]
  ? Comparison.Greater
  : CreateStrArr<B> extends [...CreateStrArr<A>, ...(infer _)]
    ? Comparison.Lower
    : A extends `${infer FirstD}${infer Rest}`
      ? B extends `${infer FirstD2}${infer Rest2}`
        ? CompareDigit<FirstD, FirstD2> extends Comparison.Equal
          ? _CompareStrings<Rest, Rest2>
          : CompareDigit<FirstD, FirstD2>
        : never
      : never;

type Comparator<A extends number, B extends number> =
  `${A}` extends `${B}`
    ? Comparison.Equal
    : `${A}` extends `-${infer Num1}`
      ? `${B}` extends `-${infer Num2}`
        ? _CompareStrings<Num2, Num1>
        : Comparison.Lower
      : `${B}` extends `-${infer _}`
        ? Comparison.Greater
        : _CompareStrings<`${A}`, `${B}`>
