let it:
  ( string, ~timeout:int=?, ~retries:int=?, ~slow:int=?
  , ((~error:Js.Exn.t=?, unit) => unit) => unit
  ) => unit
  = description => Internal.With_Options.make'(Internal.Async.it, ~description)

and before:
  ( ~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?
  , ((~error:Js.Exn.t=?, unit) => unit) => unit
  ) => unit
  = Internal.With_Options.make'(Internal.Async.before)

and after:
  ( ~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?
  , ((~error:Js.Exn.t=?, unit) => unit) => unit
  ) => unit
  = Internal.With_Options.make'(Internal.Async.after)

and before_each:
  ( ~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?
  , ((~error:Js.Exn.t=?, unit) => unit) => unit
  ) => unit
  = Internal.With_Options.make'(Internal.Async.before_each)

and after_each:
  ( ~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?
  , ((~error:Js.Exn.t=?, unit) => unit) => unit
  ) => unit
  = Internal.With_Options.make'(Internal.Async.after_each)
