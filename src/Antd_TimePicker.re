type timePickerProps('a) = Js.t({. timePickerProps: int} as 'a);

[@bs.obj]
external makeTimePickerProps :
  /* todo */
  (~id: string=?, ~className: string=?, ~style: ReactDOMRe.Style.t=?, unit) =>
  timePickerProps(_) =
  "";