[@bs.module] external switcher: ReasonReact.reactClass = "antd/lib/switch";

[%bs.raw {|require("antd/lib/switch/style")|}];

[@bs.deriving jsConverter]
type size = [ | `default | `small];

[@bs.obj]
external makeProps:
  (
    ~prefixCls: string=?,
    ~size: string=?,
    ~className: string=?,
    ~checked: bool=?,
    ~defaultChecked: bool=?,
    ~onChange: bool => unit=?,
    ~checkedChildren: ReasonReact.reactElement=?,
    ~unCheckedChildren: ReasonReact.reactElement=?,
    ~disabled: bool=?,
    ~loading: bool=?,
    ~autoFocus: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~prefixCls=?,
      ~size=?,
      ~className=?,
      ~checked=?,
      ~defaultChecked=?,
      ~onChange=?,
      ~checkedChildren=?,
      ~unCheckedChildren=?,
      ~disabled=?,
      ~loading=?,
      ~autoFocus=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=switcher,
    ~props=
      makeProps(
        ~prefixCls?,
        ~size=?Js.Option.map((. b) => sizeToJs(b), size),
        ~className?,
        ~checked?,
        ~defaultChecked?,
        ~onChange?,
        ~checkedChildren?,
        ~unCheckedChildren?,
        ~disabled?,
        ~loading?,
        ~autoFocus?,
        ~style?,
        (),
      ),
    children,
  );