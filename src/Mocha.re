let describe:
  (string, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => unit) => unit
  = description => Internal.With_Options.make(Internal.Sync.describe, ~description)

and it:
  (string, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => unit) => unit
  = description => Internal.With_Options.make(Internal.Sync.it, ~description)

and before:
  (~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => unit) => unit
  = (~description=?) => Internal.With_Options.make(Internal.Sync.before, ~description=?)

and after:
  (~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => unit) => unit
  = (~description=?) => Internal.With_Options.make(Internal.Sync.after, ~description=?)

and before_each:
  (~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => unit) => unit
  = (~description=?) => Internal.With_Options.make(Internal.Sync.before_each, ~description=?)

and after_each:
  (~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => unit) => unit
  = (~description=?) => Internal.With_Options.make(Internal.Sync.after_each, ~description=?)
