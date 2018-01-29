type mocha;
type done_callback = Js.Nullable.t(Js.Exn.t) => unit;

/* Mocha bindings on `this` for `describe` and `it` functions */
module This = {
  [@bs.send] external timeout: (mocha, int) => unit = "timeout";
  [@bs.send] external retries: (mocha, int) => unit = "retries";
  [@bs.send] external slow: (mocha, int) => unit = "slow";
  [@bs.send] external skip: (mocha, unit) => unit = "skip";
};

module Sync = {
  [@bs.val]
  external describe: (~description:string=?, [@bs.this] (mocha, unit) => unit) => unit = "describe";
  [@bs.val]
  external it: (~description:string=?, [@bs.this] (mocha, unit) => unit) => unit = "it";
  [@bs.val]
  external before: (~description:string=?, [@bs.this] (mocha, unit) => unit) => unit = "before";
  [@bs.val]
  external after: (~description:string=?, [@bs.this] (mocha, unit) => unit) => unit = "after";
  [@bs.val]
  external before_each: (~description:string=?, [@bs.this] (mocha, unit) => unit) => unit = "beforeEach";
  [@bs.val]
  external after_each: (~description:string=?, [@bs.this] (mocha, unit) => unit) => unit = "afterEach";
};

module Async = {
  [@bs.val]
  external it: (~description:string=?, [@bs.this] (mocha, done_callback) => unit) => unit = "it";
  [@bs.val]
  external before: (~description:string=?, [@bs.this] (mocha, done_callback) => unit) => unit = "before";
  [@bs.val]
  external after: (~description:string=?, [@bs.this] (mocha, done_callback) => unit) => unit = "after";
  [@bs.val]
  external before_each: (~description:string=?, [@bs.this] (mocha, done_callback) => unit) => unit = "beforeEach";
  [@bs.val]
  external after_each: (~description:string=?, [@bs.this] (mocha, done_callback) => unit) => unit = "afterEach";
};

module Promise = {
  [@bs.val]
  external it: (~description:string=?, [@bs.this] (mocha, unit) => Js.Promise.t('a)) => unit = "it";
  [@bs.val]
  external before: (~description:string=?, [@bs.this] (mocha, unit) => Js.Promise.t('a)) => unit = "before";
  [@bs.val]
  external after: (~description:string=?, [@bs.this] (mocha, unit) => Js.Promise.t('a)) => unit = "after";
  [@bs.val]
  external before_each: (~description:string=?, [@bs.this] (mocha, unit) => Js.Promise.t('a)) => unit = "beforeEach";
  [@bs.val]
  external after_each: (~description:string=?, [@bs.this] (mocha, unit) => Js.Promise.t('a)) => unit = "afterEach";
};

/* Constructs a function that can take the options that are normally set with `this` in mocha */
module With_Options = {
  let make:
    ( ((~description:string=?, [@bs.this] (mocha, 'a) => 'b) => unit),
      ~description:string=?, ~timeout: int=?, ~retries: int=?, ~slow: int=?, 'a => 'b
    ) => unit =
    (fn, ~description=?, ~timeout=?, ~retries=?, ~slow=?, done_callback) =>
      fn(~description=?, [@bs.this] (this, ()) => {
        switch timeout { | Some(milliseconds) => This.timeout(this, milliseconds) | None => () };
        switch retries { | Some(max_retries)  => This.retries(this,  max_retries) | None => () };
        switch slow    { | Some(milliseconds) => This.slow   (this, milliseconds) | None => () };
        done_callback()
      });

  let make':
    ( ((~description:string=?, [@bs.this] (mocha, 'a) => 'b) => unit)
    ,  ~description:string=?, ~timeout: int=?, ~retries: int=?, ~slow: int=?
    , ((~error:Js.Exn.t=?, unit) => unit) => unit
    ) => unit =
    (fn, ~description=?, ~timeout=?, ~retries=?, ~slow=?, done_callback) =>
      fn(~description=?, [@bs.this] (this, done_callback') => {
        switch timeout { | Some(milliseconds) => This.timeout(this, milliseconds) | None => () };
        switch retries { | Some(max_retries)  => This.retries(this,  max_retries) | None => () };
        switch slow    { | Some(milliseconds) => This.slow   (this, milliseconds) | None => () };

        let done_fn = (~error=?, ()) => done_callback'(Js.Nullable.from_opt(error));
        done_callback(done_fn);
      });
};
