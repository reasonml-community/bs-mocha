module Labels = {
  [@bs.module "assert"]
  external deep_equal: (~actual:'a, ~expected:'a, ~message:string=?) => unit = "deepEqual";

  [@bs.module "assert"]
  external deep_strict_equal: (~actual:'a, ~expected:'a, ~message:string=?) => unit = "deepStrictEqual";

  [@bs.module "assert"]
  external does_not_throw: (~block:('a => 'b), ~error:Js.Exn.t, ~message:string=?) => unit = "doesNotThrow";

  [@bs.module "assert"]
  external equal: (~actual:'a, ~expected:'a, ~message:string=?) => unit = "equal";

  [@bs.module "assert"]
  external fail: (~message:'a) => unit = "fail";

  [@bs.module "assert"]
  external fail': (~actual:'a, ~expected:'a, ~message:string=?, ~operator:string=?, ~stack_start_fn:('b => 'c)=?) =>
    unit = "fail";

  [@bs.module "assert"]
  external if_error: (~value:'a) => unit = "ifError";

  [@bs.module "assert"]
  external not_deep_equal: (~actual:'a, ~expected:'a, ~message:string=?) => unit = "notDeepEqual";

  [@bs.module "assert"]
  external not_deep_strict_equal: (~actual:'a, ~expected:'a, ~message:string=?) => unit = "notDeepStrictEqual";

  [@bs.module "assert"]
  external not_equal: (~actual:'a, ~expected:'a, ~message:string=?) => unit = "notEqual";

  [@bs.module "assert"]
  external not_strict_equal: (~actual:'a, ~expected:'a, ~message:string=?) => unit = "notStrictEqual";

  [@bs.module "assert"]
  external ok: (~value:'a) => unit = "ok";

  [@bs.module "assert"]
  external strict_equal: (~actual:'a, ~expected:'a, ~message:string=?) => unit = "strictEqual";

  [@bs.module "assert"]
  external throws: (~block:('a => 'b), ~error:Js.Exn.t, ~message:string=?) => unit = "throws";
};

let deep_equal = (~message, actual, expected) => Labels.deep_equal(~actual, ~expected, ~message);

let deep_strict_equal = (~message, actual, expected) => Labels.deep_strict_equal(~actual, ~expected, ~message);

let does_not_throw = (~message, block, error) => Labels.does_not_throw(~block, ~error, ~message);

let equal = (~message, actual, expected) => Labels.equal(~actual, ~expected, ~message);

let fail = message => Labels.fail(~message);

let fail' = (~message, ~operator, ~stack_start_fn, actual, expected) =>
  Labels.fail'(~actual, ~expected, ~message, ~operator, ~stack_start_fn);

let if_error = value => Labels.if_error(~value);

let not_deep_equal = (~message, actual, expected) => Labels.not_deep_equal(~actual, ~expected, ~message);

let not_deep_strict_equal = (~message, actual, expected) => Labels.not_deep_strict_equal(~actual, ~expected, ~message);

let not_equal = (~message, actual, expected) => Labels.not_equal(~actual, ~expected, ~message);

let not_strict_equal = (~message, actual, expected) => Labels.not_strict_equal(~actual, ~expected, ~message);

let ok = value => Labels.ok(~value);

let strict_equal = (~message, actual, expected) => Labels.strict_equal(~actual, ~expected, ~message);

let throws = (~message, block, error) => Labels.throws(~block, ~error, ~message);
