type CreateMutable<Type> = {
  -readonly [Property in keyof Type]: Type[Property];
};

type TestGround = Readonly<{ A: string[] }> extends CreateMutable<
  Readonly<{ A: string[] }>
>
  ? true
  : false;

// This relies on the black magic type that compares arrow function generics
/* prettier-ignore */
type Equals<X, Y> =
    (<T>() => T extends X ? 1 : 2) extends
    (<T>() => T extends Y ? 1 : 2) ? true : false;

type IsReadonly<T, S extends keyof T> = Equals<
  Readonly<{
    [P in S]: T[S];
  }>,
  { [P in S]: T[S] }
>;

type GetReadonlyKeys<T, Key extends keyof T = keyof T> = Key extends string
  ? IsReadonly<T, Key> extends true
    ? Key
    : never
  : never;

type Ex = IsReadonly<Todo1, "description">;

// type GetReadonlyKeys<T> =
