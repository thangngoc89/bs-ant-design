[@bs.module "antd/lib/badge"]
external reactClass: ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/badge/style")|}];

[@bs.deriving jsConverter]
type status = [ | `success | `processing | `default | `error | `warning];

[@bs.obj]
external makeProps:
  (
    ~count: int=?,
    ~showZero: bool=?,
    ~overflowCount: int=?,
    ~dot: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~status: string=?,
    ~text: string=?,
    ~title: string=?,
    ~scrollNumberPrefixCls: string=?,
    ~offset: array(int)=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~count=?,
      ~showZero=?,
      ~overflowCount=?,
      ~dot=?,
      ~style=?,
      ~prefixCls=?,
      ~className=?,
      ~status=?,
      ~text=?,
      ~title=?,
      ~scrollNumberPrefixCls=?,
      ~offset=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~count?,
        ~status=?Js.Option.map((. b) => statusToJs(b), status),
        ~showZero?,
        ~overflowCount?,
        ~dot?,
        ~style?,
        ~prefixCls?,
        ~className?,
        ~text?,
        ~title?,
        ~scrollNumberPrefixCls?,
        ~offset?,
        (),
      ),
    children,
  );