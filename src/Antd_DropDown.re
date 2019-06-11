[@bs.module "antd/lib/dropdown"]
external dropdown: ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/dropdown/style")|}];

[@bs.deriving jsConverter]
type trigger = [ | `click | `hover | `contextMenu];

[@bs.deriving jsConverter]
type placement = [
  | `topLeft
  | `topCenter
  | `topRight
  | `bottomLeft
  | `bottomCenter
  | `bottomRight
];

[@bs.obj]
external makeProps:
  (
    ~trigger: array(string)=?,
    ~overlay: ReasonReact.reactElement,
    ~onVisibleChange: bool => unit=?,
    ~visible: bool=?,
    ~disabled: bool=?,
    ~align: Js.t({..})=?,
    /* getPopupContainer?: (triggerNode: Element) => HTMLElement; */
    ~prefixCls: string=?,
    ~className: string=?,
    ~transitionName: string=?,
    ~placement: string=?,
    ~overlayClassName: string=?,
    ~overlayStyle: ReactDOMRe.Style.t=?,
    ~forceRender: bool=?,
    ~mouseEnterDelay: float=?,
    ~mouseLeaveDelay: float=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~trigger=?,
      ~overlay,
      ~onVisibleChange=?,
      ~visible=?,
      ~disabled=?,
      ~align=?,
      /* ~getPopupContainer=?, */
      ~prefixCls=?,
      ~className=?,
      ~transitionName=?,
      ~placement=?,
      ~overlayClassName=?,
      ~overlayStyle=?,
      ~forceRender=?,
      ~mouseEnterDelay=?,
      ~mouseLeaveDelay=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=dropdown,
    ~props=
      makeProps(
        ~trigger=?
          Js.Option.map((. b) => b |> Array.map(triggerToJs), trigger),
        ~overlay,
        ~onVisibleChange?,
        ~visible?,
        ~disabled?,
        ~align?,
        /* ~getPopupContainer?, */
        ~prefixCls?,
        ~className?,
        ~transitionName?,
        ~placement=?Js.Option.map((. b) => placementToJs(b), placement),
        ~overlayClassName?,
        ~overlayStyle?,
        ~forceRender?,
        ~mouseEnterDelay?,
        ~mouseLeaveDelay?,
        (),
      ),
    children,
  );