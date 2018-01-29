let it:
  (string, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => Js.Promise.t('a)) => unit
  = description => Internal.With_Options.make(Internal.Promise.it, ~description)

and before:
  (~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => Js.Promise.t('a)) => unit
  = (~description=?) => Internal.With_Options.make(Internal.Promise.before, ~description=?)

and after:
  (~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => Js.Promise.t('a)) => unit
  = (~description=?) => Internal.With_Options.make(Internal.Promise.after, ~description=?)

and before_each:
  (~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => Js.Promise.t('a)) => unit
  = (~description=?) => Internal.With_Options.make(Internal.Promise.before_each, ~description=?)

and after_each:
  (~description:string=?, ~timeout:int=?, ~retries:int=?, ~slow:int=?, unit => Js.Promise.t('a)) => unit
  = (~description=?) => Internal.With_Options.make(Internal.Promise.after_each, ~description=?)
